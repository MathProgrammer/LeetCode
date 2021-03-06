#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    string sortSentence(string s) 
    {
        vector <pair <int, string> > words; 
        
        string current_word;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                continue;
            }
            
            if('1' <= s[i] && s[i] <= '9')
            {
                words.push_back(make_pair(s[i] - '0', current_word));
                
                current_word = "";
                
                continue;
            }
            
            current_word += s[i];
        }
        
        sort(words.begin(), words.end());
        
        string sentence; 
        for(int i = 0; i < words.size(); i++)
        {
            sentence += words[i].second; 
            
            if(i + 1 != words.size())
            {
                sentence += " ";
            }
        }
        
        return sentence;
    }
};
