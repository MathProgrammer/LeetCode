class Solution {
public:
    long long minimumCost(string S) {
        
        vector <vector <long long> > prefix_cost(S.size(), vector <long long> (2, 0));
        for(int i = 0; i < S.size(); i++)
        {
            for(int bit = 0; bit <= 1; bit++)
            {
                if(S[i] == '0' + bit)
                {
                    prefix_cost[i][bit] = (i == 0 ? 0 : prefix_cost[i - 1][bit]);
                }
                else 
                {
                    prefix_cost[i][bit] = (i + 1) + (i == 0 ? 0 : prefix_cost[i - 1][bit^1]);
                }
            }
        }
        
        vector <vector <long long> > suffix_cost(S.size(), vector <long long> (2, 0));
        for(int i = S.size() - 1; i >= 0; i--)
        {
            for(int bit = 0; bit <= 1; bit++)
            {
                if(S[i] == '0' + bit)
                {
                    suffix_cost[i][bit] = (i == S.size() - 1 ? 0 : suffix_cost[i + 1][bit]);
                }
                else 
                {
                    suffix_cost[i][bit] = (S.size() - i) + (i == S.size() - 1 ? 0 : suffix_cost[i + 1][bit^1]);
                }
            }
        }
        
        long long only_prefix = min(prefix_cost[S.size() - 1][0], prefix_cost[S.size() - 1][1]);
        long long only_suffix = min(suffix_cost[0][0], suffix_cost[0][1]);
        long long answer = min(only_prefix, only_suffix);
        for(int i = 1; i < S.size() - 1; i++)
        {
            for(int bit = 0; bit <= 1; bit++)
            {
                answer = min(answer, prefix_cost[i][bit] + suffix_cost[i + 1][bit]);
            }
        }
        
        return answer;
    }
};
