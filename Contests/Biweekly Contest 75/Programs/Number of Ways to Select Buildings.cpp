class Solution {
public:
    long long numberOfWays(string &S) 
    {
        vector <int> prefix_sum(S.size());
        prefix_sum[0] = (S[0] == '1');
        for(int i = 1; i < S.size(); i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + (S[i] == '1');
        }
        
        vector <int> suffix_sum(S.size() + 1);
        for(int i = S.size() - 1; i >= 0; i--)
        {
            suffix_sum[i] = suffix_sum[i + 1] + (S[i] == '1');
        }
        
        long long answer = 0;
        for(int middle = 1; middle < S.size() - 1; middle++)
        {
            long long prefix_0s = middle - prefix_sum[middle - 1], prefix_1s = prefix_sum[middle - 1];
            long long suffix_0s = S.size() - 1 - middle - suffix_sum[middle + 1], suffix_1s = suffix_sum[middle + 1];
            
            
            switch(S[middle])
            {
                case '0': answer += prefix_1s*suffix_1s; 
                                    break;
                    
                case '1': answer += prefix_0s*suffix_0s;
                                    break;
            }
        }
        
        return answer;
    }
};
