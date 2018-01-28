#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int coinChange(vector<int>& coins, int amount)
    {
        const int oo = 1e9;
        int no_of_coins = coins.size();

        int minimum_coins[amount + 1];
        minimum_coins[0] = 0;
        for(int i = 1; i <= amount; i++)
            minimum_coins[i] = oo;

        for(int i = 0; i < no_of_coins; i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
                minimum_coins[j] = min(minimum_coins[j], 1 + minimum_coins[j - coins[i]]);
            }
        }

        return (minimum_coins[amount] >= oo ? -1 : minimum_coins[amount]);
    }
};
