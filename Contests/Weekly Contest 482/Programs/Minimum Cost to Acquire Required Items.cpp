#include <algorithm> 

using namespace std; 

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) 
    {
        long long common_need = min(need1, need2);
        costBoth = min(costBoth, cost1 + cost2);

        long long cost = 0; 
        cost += costBoth*common_need; 
        need1 -= common_need; 
        need2 -= common_need; 

        cost += need1*1LL*min(cost1, costBoth); 
        cost += need2*1LL*min(cost2, costBoth);
        return cost;
    }
};