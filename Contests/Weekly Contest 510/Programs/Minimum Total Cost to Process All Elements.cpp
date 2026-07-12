#include <vector> 

using namespace std; 

class Solution 
{
    private: 
    int ceil(int numerator, int denominator)
    {
        if(numerator < 0)
        {
            return 0;
        }

        return numerator/denominator + (numerator%denominator != 0);
    }

    public:
    int minimumCost(vector<int>& nums, int k) 
    {
        const int MOD = 1e9 + 7; 
        int last_cost= 0, budget = k;
        for(int n : nums)
        {
            int no_of_purchases = max(0, ceil(n - budget, k));
            budget += no_of_purchases*k;

            budget -= n; 
        
            last_cost += no_of_purchases;
            last_cost %= MOD;
        }

        long long cost = (last_cost*1LL*(last_cost + 1))/2;
        cost %= MOD;
        
        return cost;
    }
};