class Solution 
{
    public:
    int minimumTime(string S) 
    {
        vector <int> prefix_moves(S.size(), 0);
        for(int i = 0, length = 1; i < S.size(); i++, length++)
        {
            if(i == 0)
            {
                prefix_moves[i] = min(length, 2*(S[i] == '1'));
            }
            else 
            {
                prefix_moves[i] = min(length, prefix_moves[i - 1] + 2*(S[i] == '1'));
            }
        }
        
        vector <int> suffix_moves(S.size() + 1, 0);
        for(int i = S.size() - 1, length = 1; i >= 0; i--, length++)
        {
            if(i == S.size() - 1)
            {
                suffix_moves[i] = min(length, 2*(S[i] == '1'));
            }
            else 
            {
                suffix_moves[i] = min(length, suffix_moves[i + 1] + 2*(S[i] == '1'));
            }
        }
        
        int answer = S.size();
        for(int i = 0; i < S.size(); i++)
        {
            answer = min(answer, prefix_moves[i] + suffix_moves[i + 1]);
        }
        
        return answer;
    }
};
