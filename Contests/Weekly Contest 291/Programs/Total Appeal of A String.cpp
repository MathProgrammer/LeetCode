class Solution {
public:
    long long appealSum(string S) 
    {
        const int NO_OF_ALPHABETS = 26, NOT_FOUND = -1;
        long long answer = 0;
        vector <int> first_index(NO_OF_ALPHABETS, NOT_FOUND);    
        vector <long long> contribution(S.size(), 0);
        for(int i = 0; i < S.size(); i++)
        {   
            if(i == 0)
            {
                contribution[i] = 1;
            }
            else if(S[i] == S[i - 1])
            {
                contribution[i] = contribution[i - 1] + 1;
            }
            else 
            {
                if(first_index[S[i] - 'a'] == NOT_FOUND)
                {
                    contribution[i] = contribution[i - 1] + i + 1;
                }
                else 
                {
                    contribution[i] = contribution[i - 1] + (i - first_index[S[i] - 'a']) + 1;
                }
            }
            
            first_index[S[i] - 'a'] = i + 1;
            
            answer += contribution[i];
        }
        
        return answer;
    }
};
