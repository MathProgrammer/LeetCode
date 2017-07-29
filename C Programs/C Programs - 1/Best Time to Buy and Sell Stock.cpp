#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        const int oo = 1e9;
        int no_of_days = prices.size();
        vector <int> minimum_price_till(no_of_days, oo);

        for(unsigned int day_i = 0; day_i < no_of_days ; day_i++)
        {
            if(day_i == 0)
                minimum_price_till[day_i] = prices[day_i];
            else
                minimum_price_till[day_i] = min(minimum_price_till[day_i - 1], prices[day_i]);
        }

        int maximum_profit = 0;
        for(unsigned int day_i = 0; day_i < no_of_days; day_i++)
        {
            int maximum_profit_by_selling_today = 0;

            if(day_i == 0)
                maximum_profit_by_selling_today = 0;
            else
                maximum_profit_by_selling_today = prices[day_i] - minimum_price_till[day_i - 1];

            maximum_profit = max(maximum_profit, maximum_profit_by_selling_today);
        }

        return maximum_profit;
    }
};

