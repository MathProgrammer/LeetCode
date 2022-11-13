class Solution {
public:
    int maxPalindromes(string S, int k) 
    {
        vector <vector <int> > is_palindrome(S.size(), vector <int> (S.size(), 0));  
        for(int length = 1; length <= S.size(); length++)
        {
            for(int left = 0, right = left + length - 1; right < S.size(); left++, right++)
            {
                if(length == 1)
                {
                    is_palindrome[left][right] = true;
                }
                else if(length == 2)
                {
                    is_palindrome[left][right] = (S[left] == S[right]);
                }
                else
                {
                    is_palindrome[left][right] = ( (S[left] == S[right])&is_palindrome[left + 1][right - 1]);
                }
            }
        }
        
        vector <int> maximum_palindromes_till(S.size(), 0);
        for(int i = k - 1; i < S.size(); i++)
        {
            maximum_palindromes_till[i] = is_palindrome[0][i];
            
            if(i >= 1)
            {
                maximum_palindromes_till[i] = max(maximum_palindromes_till[i - 1], is_palindrome[0][i]);
            }
            
            for(int j = i - k + 1; j > 0; j--)
            {
                if(is_palindrome[j][i])
                {
                    maximum_palindromes_till[i] = max(maximum_palindromes_till[i], 1 + maximum_palindromes_till[j - 1]);
                }
            }
        }
        
        return maximum_palindromes_till[S.size() - 1];
    }
};
