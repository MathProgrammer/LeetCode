class Solution 
{
    public:
    int countHomogenous(string s) 
    {
        const int MOD = 1e9 + 7;
        
        int answer = 0;
        int current_substring = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(i > 0 && s[i] == s[i - 1])
            {
                current_substring++;
            }
            else 
            {
                current_substring = 1;
            }
            
            answer = (answer + current_substring)%MOD;
        }
        
        return answer;
    }
};
