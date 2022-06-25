class Solution {
public:
    int countAsterisks(string S) 
    {
        int answer = 0;
        int bar_count = 0;
        const char ASTERISK = '*', BAR = '|';
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == BAR)
            {
                bar_count++;
            }
            
            if(bar_count%2 == 0 && S[i] == ASTERISK)
            {
                answer++;
            }
        }
        
        return answer;
    }
};
