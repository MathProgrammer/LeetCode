class Solution {
public:
    long long minimumCost(string S) {
        
        vector <int> last_different(S.size());
        last_different[0] = -1;
        for(int i = 1; i < S.size(); i++)
        {
            last_different[i] = (S[i] != S[i - 1] ? i - 1: last_different[i - 1]);
        }
        
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
                    prefix_cost[i][bit] = (i + 1);
                    
                    if(last_different[i] != -1)
                    {
                        prefix_cost[i][bit] += prefix_cost[last_different[i]][bit^1];
                    }
                }
            }
        }
        
        vector <int> next_different(S.size());
        next_different[S.size() - 1] = S.size(); 
        for(int i = S.size() - 2; i >= 0; i--)
        {
            next_different[i] = (S[i] != S[i + 1] ? i + 1 : next_different[i + 1]);
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
                    suffix_cost[i][bit] = (S.size() - i);
                    
                    if(next_different[i] != S.size())
                    {
                        suffix_cost[i][bit] += suffix_cost[next_different[i]][bit^1];
                    }
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