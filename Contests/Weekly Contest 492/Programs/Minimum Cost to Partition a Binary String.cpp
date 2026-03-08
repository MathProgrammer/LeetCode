#include <vector> 
#include <algorithm> 

using namespace std; 

class Solution 
{
    private: 
    long long get_sum(vector <int> &prefix_sum, int left, int right)
    {
        return prefix_sum[right] - (left == 0 ? 0 : prefix_sum[left - 1]);
    }
    
    long long get_min_cost(int left, int right, vector <int> &prefix_sum, int cost1, int cost2)
    {
        int range_1s = get_sum(prefix_sum, left, right);
        int length = right - left + 1;
        
        if(range_1s == 0)
        {
            return cost2;
        }

        long long cost_without_cutting = length*1LL*range_1s*cost1;
        long long cost_after_cutting = cost_without_cutting; 

        if(length%2 == 0)
        {
            int mid = (left + right)/2;
            cost_after_cutting = get_min_cost(left, mid, prefix_sum, cost1, cost2) + 
                get_min_cost(mid + 1, right, prefix_sum, cost1, cost2);
        }

        return min(cost_without_cutting, cost_after_cutting);
    }
    
    public:
    long long minCost(string s, int encCost, int flatCost) 
    {
        vector <int> prefix_sum(s.size()); 
        for(int i = 0; i < s.size(); i++)
        {
            prefix_sum[i] = (s[i] == '1') + (i > 0 ? prefix_sum[i - 1] : 0);
        }

        return get_min_cost(0, s.size() - 1, prefix_sum, encCost, flatCost);
    }
};