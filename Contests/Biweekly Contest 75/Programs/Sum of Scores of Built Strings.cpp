class Solution {
public:
    long long sumScores(string S) 
    {
        vector <int> Z(S.size());
        Z[0] = S.size();
        for(int i = 1, left = 0, right = 0; i < S.size(); i++)
        {
            if(i <= right)
            {
                Z[i] = min(Z[i  - left], right - i + 1);
            }
            
            while(i + Z[i]  < S.size() && S[i + Z[i]] == S[Z[i]])
            {
                Z[i]++;
            }
            
            if(right < i + Z[i])
            {
                left = i;
                right = i + Z[i] - 1;
            }
        }
        
        long long answer = 0;
        for(int i = 0; i < S.size(); i++)
        {
            answer += Z[i];
        }
        
        return answer;
    }
};
