const int MAX_N = 105;
int max_profit[MAX_N][MAX_N], temp_max_profit[MAX_N][MAX_N];

class Solution 
{
    public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        const int MOD = 1e9 + 7;
        memset(max_profit, 0, sizeof(max_profit));
        memset(temp_max_profit, 0, sizeof(temp_max_profit));
        
        max_profit[0][0] = 1;
        
        for(int i = 0; i < profit.size(); i++)
        {
            for(int p = 0; p <= minProfit; p++)
            {
                for(int g = 0; g <= n; g++)
                {
                    temp_max_profit[p][g] = max_profit[p][g];
                }
            }
            
            for(int p = 0; p <= minProfit; p++)
            {
                for(int g = group[i]; g <= n; g++)
                {
                    int profit_here = min(p + profit[i], minProfit);
                    
                    max_profit[profit_here][g] += temp_max_profit[p][g - group[i]];
                    
                    max_profit[profit_here][g] %= MOD;
                }
            }
        }
        
        int answer = 0;
        for(int g = 0; g <= n; g++)
        {
            answer = (answer + max_profit[minProfit][g])%MOD;
        }
        
        return answer;
    }
};
