#include <vector> 
#include <algorithm> 

using namespace std; 

class Solution 
{
    private: 
    int vowel_count(string s)
    {
        int vowels = 0;
        for(int i = 0; i < s.size(); i++)
        {
            switch(s[i])
            {
                case 'a': 
                case 'e': 
                case 'i': 
                case 'o': 
                case 'u': 
                    vowels++;
            }
        }

        return vowels;
    }
    
    public:
    string reverseWords(string s) 
    {
        string first_word, final_text; 
        string current_word; 
        for(int i = 0; i <= s.size(); i++)
        {
            if(i < s.size() && s[i] != ' ')
            {
                current_word += s[i];
                continue;
            }
            
            if(first_word == "")
            {
                first_word = current_word; 
                final_text = first_word; 
                current_word = "";
                continue;
            }

            if(vowel_count(first_word) == vowel_count(current_word))
            {
                reverse(current_word.begin(), current_word.end());
            }

            final_text += " " + current_word;
            current_word = "";
        }
        
        return final_text;
    }
};