class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        
        long long answer = 0;
        vector <long long> no_of_descents(prices.size(), 1);
        for(int i = 0; i < prices.size(); i++)
        {
            if(i > 0 && prices[i] == prices[i - 1] - 1)
            {
                no_of_descents[i] += no_of_descents[i - 1];
            }
            
            answer += no_of_descents[i];
        }
        
        return answer;
    }
