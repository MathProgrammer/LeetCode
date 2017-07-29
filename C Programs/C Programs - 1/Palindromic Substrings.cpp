#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {

        typedef vector <int> v_int;
        vector <v_int> is_palindrome(s.length(), v_int(s.length(), false));

        for(unsigned int i = 0; i < s.length(); i++)
            is_palindrome[i][i] = true;
        int no_of_palindrome_strings = s.length();

        for(int length = 2; length <= s.length(); length++)
        {
            int start = 0;
            int end = start + (length - 1);

            for(; end < s.length(); start++, end++)
            {
                if(s[start] == s[end])
                {
                    if(start + 1 == end)
                    {
                        is_palindrome[start][end] = true;
                        no_of_palindrome_strings++;
                    }
                    else
                    {
                        if(is_palindrome[start + 1][end - 1])
                        {
                            is_palindrome[start][end] = true;
                            no_of_palindrome_strings++;
                        }
                    }
                }
            }
        }

        return no_of_palindrome_strings;
    }
};
