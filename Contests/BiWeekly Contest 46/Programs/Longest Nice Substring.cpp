class Solution 
{
    public:
    
    string longestNiceSubstring(string s) 
    {    
        string answer;
        
        set <char> distinct;
        
        for(int i = 0; i < s.size(); i++)
        {
            distinct.insert(s[i]);
        }
        
        for(int i = 0; i < s.size(); i++)
        {
            if('a' <= s[i] && s[i] <= 'z')
            {
                if(distinct.find(s[i] + 'A' - 'a') != distinct.end())
                {
                    continue;
                }
            }
            
            if('A' <= s[i] && s[i] <= 'Z')
            {
                if(distinct.find(s[i] + 'a' - 'A') != distinct.end())
                {
                    continue;
                }
            }
            
            string left_answer = longestNiceSubstring(s.substr(0, i)); 
            string right_answer = longestNiceSubstring(s.substr(i + 1, s.size() - (i + 1)));
            
            if(left_answer.size() < right_answer.size())
            {
                return right_answer;
            }
            
            return left_answer;
        } 
        
        return s;
    }
};
