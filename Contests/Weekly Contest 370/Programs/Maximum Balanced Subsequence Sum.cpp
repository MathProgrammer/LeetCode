#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    #define LEFT(n) (2*n)
    #define RIGHT(n) (2*n + 1)

    long long get_max(vector <long long> &tree, int n, int left, int right, int query_left, int query_right)
    {
        if(query_right < left || right < query_left || right < left || query_right < query_left)
        {
            return 0;
        }

        if(query_left <= left && right <= query_right)
        {
            return tree[n];
        }

        int mid = (left + right)/2;
        long long left_max = get_max(tree, LEFT(n), left, mid, query_left, query_right);
        long long right_max = get_max(tree, RIGHT(n), mid + 1, right, query_left, query_right);

        return max(left_max, right_max);
    }

    void update(vector <long long> &tree, int n, int left, int right, int position, long long value)
    {
        if(position < left || right < position)
        {
            return;
        }

        if(left == right)
        {
            tree[n] = max(tree[n], value);
            return;
        }

        int mid = (left + right)/2;
        update(tree, LEFT(n), left, mid, position, value);
        update(tree, RIGHT(n), mid + 1, right, position, value);

        tree[n] = max(tree[LEFT(n)], tree[RIGHT(n)]);
    }

    long long maxBalancedSubsequenceSum(vector<int>& A)
    {
        int no_of_elements = A.size();
        set <int> values;
        for(int i = 0; i < no_of_elements; i++)
        {
            values.insert(A[i] - i);
        }

        int id = 1;
        map <int, int> compressed_id;
        for(int v : values)
        {
            compressed_id[v] = id++;
        }



        const int oo = 1e9 + 9;
        long long answer = A[0];
        vector <long long> max_tree(4* no_of_elements + 5, 0);
        for(int i = 0; i <  no_of_elements; i++)
        {
            int current_value = A[i] - i;
            int current_id = compressed_id[current_value];

            long long max_sum_ending_here = A[i] + get_max(max_tree, 1, 1, no_of_elements, 1, current_id);
            update(max_tree, 1, 1, no_of_elements, current_id, max_sum_ending_here);

            answer = max(answer, max_sum_ending_here);
        }

        return answer;
    }
};
