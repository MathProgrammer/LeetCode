#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        const int oo = 1e9;
        int no_of_days = prices.size();

        int minimum_price = oo, maximum_profit = 0;

        for(int day_i = 0; day_i < no_of_days ; day_i++)
        {
            if(prices[day_i] < minimum_price)
                minimum_price = prices[day_i];
            else
                maximum_profit = max(maximum_profit, prices[day_i] - minimum_price);
        }


        return maximum_profit;
    }
};
