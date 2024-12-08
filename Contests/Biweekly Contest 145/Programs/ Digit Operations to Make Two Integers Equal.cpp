#include <vector> 
#include <queue>

using namespace std; 

class Solution 
{
    public:
    void sieve(vector <int> &is_prime, int N)
    {
        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i < N; i++)
        {
            for(int multiple = 2*i; multiple < N; multiple += i)
            {
                is_prime[multiple] = false;
            }
        }
    }

    vector <int> get_children(int n)
    {
        int original_n = n;
        vector <int> children;
        
        vector <int> steps = vector <int> {1, 10, 100, 1000};
        for(int i = 0; i < steps.size() && n > 0; i++)
        {
            int digit = n%10; 
            if(digit != 9)
            {
                int adding_step = original_n + steps[i];
                children.push_back(adding_step);
            }

            if(digit != 0)
            {
                int subtracting_step = original_n - steps[i];
                children.push_back(subtracting_step);
            }
            
            n /= 10;
        }

        return children;
    }

    int minOperations(int n, int m) 
    {
        const int MAX_N = 1e4 + 5, oo = 1e9;
        vector <int> is_prime(MAX_N, true); 
        sieve(is_prime, MAX_N);

        vector <int> min_cost(MAX_N, oo);
        queue <int> Q; 

        if(!is_prime[n])
        {
            min_cost[n] = n; 
            Q.push(n); 
        }

        while(!Q.empty())
        {
            int v = Q.front(); 
            Q.pop(); 

            vector <int> children = get_children(v);
            for(int child : children)
            {
                if(!is_prime[child] && 
                    min_cost[v] + child < min_cost[child])
                {
                    min_cost[child] = min_cost[v] + child;
                    Q.push(child);
                }
            }
        }

        int answer = (min_cost[m] == oo ? -1 : min_cost[m]);
        return answer;
    }
};