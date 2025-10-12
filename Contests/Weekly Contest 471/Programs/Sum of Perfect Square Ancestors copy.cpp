#include <vector> 
#include <map> 

using namespace std; 

class Solution {
    private: 
    void sieve(vector <int> &square_free, int N)
    {
        vector <int> largest_prime_factor(N); 
        for(int i = 2; i < N; i++)
        {
            if(largest_prime_factor[i] != 0)
            {
                continue;
            }

            for(int multiple = i; multiple < N; multiple += i)
            {
                largest_prime_factor[multiple] = i;
            }
        }

        for(int i = 2; i < N; i++)
        {
            int current_i = i, exponent = 0, p = largest_prime_factor[i];
            while(current_i%p == 0)
            {
                current_i /= p; 
                exponent++;
            }

            square_free[i] = (exponent%2 == 1 ? p : 1)*square_free[current_i];
        }
    }

    long long dfs(
        vector <vector <int> > &tree, 
        int v, 
        int parent_v, 
        vector <int> &nums,
        vector <int> &square_free, 
        map <int, int> &frequency)
    {
        int squaree_free_v = square_free[nums[v]];
        long long answer_this_subtree = frequency[squaree_free_v];
        frequency[squaree_free_v]++;

        for(int child_v : tree[v])
        {
            if(child_v == parent_v)
            {
                continue;
            }

            answer_this_subtree += dfs(tree, child_v, v, nums, square_free, frequency);
        }

        frequency[squaree_free_v]--;
        return answer_this_subtree;
    }

public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        const int MAX_N = 1e5 + 5;
        vector <int> square_free(MAX_N, 1); 
        sieve(square_free, MAX_N);

        vector <vector <int> > tree(n + 1); 
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1]; 
            tree[u].push_back(v); 
            tree[v].push_back(u);
        }

        map <int, int> frequency;
        long long sum = dfs(tree, 0, -1, nums, square_free, frequency); 

        return sum;
    }
};