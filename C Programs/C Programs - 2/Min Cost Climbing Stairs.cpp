#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector <int> min_cost(cost.size() + 2, 0);

        for(int i = cost.size() - 1; i >= 0; i--)
        {
            min_cost[i] = cost[i] + min(min_cost[i + 1], min_cost[i + 2]);
        }

        return min(min_cost[0], min_cost[1]);
    }
};
