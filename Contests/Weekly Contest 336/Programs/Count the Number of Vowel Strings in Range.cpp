class Solution {
public:
    
    int is_vowel(char ch)
    {
        switch(ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                        return true;
            default : 
                        return false;
        }
    }
    
    int is_vowel_string(string S)
    {
        return ( is_vowel(S[0])&&is_vowel(S[S.size() - 1]) );
    }
    
    int vowelStrings(vector<string>& words, int left, int right) {
        
        int answer = 0;
        for(int i = left; i <= right; i++)
        {
            answer += is_vowel_string(words[i]);
        }
        
        return answer;
    }
};
