#include <vector> 
#include <map> 

using namespace std; 

class Solution {
    public:
        int maxSubstrings(string word) 
        {
            map <int, int> last_occurence; 
            vector <int> most_words_till(word.size()); 
            for(int i = 3; i < word.size(); i++)
            {
                last_occurence[word[i - 3]] = i - 3; 
                most_words_till[i] = most_words_till[i - 1];
    
                if(last_occurence.count(word[i]) == 0)
                {
                    continue;
                }
    
                int last_word_start = last_occurence[word[i]];
                int words_with_last_ending_here = 1 + (last_word_start == 0 ? 0 : most_words_till[last_word_start - 1]);
                most_words_till[i] = max(most_words_till[i], words_with_last_ending_here);
            }
    
            return most_words_till.back();
        }
    };