#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        vector <vector <int> > longest_palindrome_in_between(s.length(), vector <int>(s.length(), 0));

        for(unsigned int i = 0; i < s.length(); i++)
            longest_palindrome_in_between[i][i] = 1;

        for(unsigned int length = 2; length <= s.length(); length++)
        {
            int start = 0;
            int end = start + (length - 1);

            for(; end <= s.length() - 1; start++, end++)
            {
                if(s[start] == s[end])
                {
                    if(start + 1 == end)
                        longest_palindrome_in_between[start][end] = 2;
                    else
                        longest_palindrome_in_between[start][end] = 2 + longest_palindrome_in_between[start + 1][end - 1];
                }
                else
                {
                    longest_palindrome_in_between[start][end] = max(longest_palindrome_in_between[start + 1][end],
                                                                    longest_palindrome_in_between[start][end - 1]);
                }
            }
        }

        return longest_palindrome_in_between[0][s.length()-1];
    }
};
