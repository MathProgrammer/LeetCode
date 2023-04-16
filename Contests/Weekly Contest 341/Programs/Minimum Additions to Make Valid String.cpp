class Solution {
public:
    int addMinimum(string word) {
        string expected = "abc";
        string final_word; 
        for(int i = 0, j = 0; i < word.size() || j != 0; j = (j + 1)%3)
        {
            if(i < word.size() && word[i] == expected[j])
            {
                final_word += word[i];
                i++;
            }
            else 
            {
                final_word += expected[j];
            }
        }
        
        return final_word.size() - word.size();
    }
};
