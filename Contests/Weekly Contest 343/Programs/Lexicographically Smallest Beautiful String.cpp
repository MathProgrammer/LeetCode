class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        const int NO_OF_ALPHABETS = 26;
        int break_point = s.size();
        int possible = false;
        string empty;
        for(int i = s.size() - 1; i >= 0 && !possible; i--)
        {
            for(int j = 1; s[i] + j < 'a' + k; j++)
            {
                if( (i - 1 >= 0 && s[i] + j == s[i - 1]) || (i - 2 >= 0 && s[i] + j == s[i - 2]) )
                {
                    continue;
                }
                   
                s[i] = s[i] + j;
                possible = true;
                break_point = i;
                break;
            }
        }
        
        for(int i = break_point + 1; i < s.size(); i++)
        {
            for(int j = 0; j < k; j++)
            {
                if( (i - 1 >= 0 && 'a' + j == s[i - 1]) || (i - 2 >= 0 && 'a' + j == s[i - 2]) )
                {
                    continue;
                }
                
                s[i] = 'a' + j;
                break;
            }
        }
        
        return (possible ? s : empty);
    }
};
