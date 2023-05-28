class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        
        int money_spent = prices[0] + prices[1];
        money = (money_spent > money ? money : money - money_spent);
        
        return money;
    }
};
