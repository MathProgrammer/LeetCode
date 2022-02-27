class Solution {
public:
    
    int starts_with(string S, string prefix)
    {
        int matches = (S.size() < prefix.size() ? false : true);
        
        for(int i = 0; i < S.size() && i < prefix.size(); i++)
        {
            if(S[i] != prefix[i])
            {
                matches = false;
            }
        }
        
        return matches;
    }
    
    int prefixCount(vector<string>& words, string pref) 
    {
        int answer = 0; 
        for(int i = 0; i < words.size(); i++)
        {
            answer += starts_with(words[i], pref);
        }
        
        return answer;
    }
};
