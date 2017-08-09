#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        string answer = "";

        typedef vector <int> v_int;
        vector <v_int> palindrome_between(s.length() + 1, v_int (s.length(), false));

        int string_length = s.length(), longest_palindrome_length = 1;

        for(int i = 0; i < string_length; i++)
            palindrome_between[i][i] = true, answer = s[i];

        for(int length = 2; length <= string_length; length++)
        {
            int start = 0;
            int end = start + (length - 1);

            for(; end < string_length ; start++, end++)
            {
                if(s[start] == s[end])
                {
                    if(start + 1 == end)
                        palindrome_between[start][end] = true;
                    else if(palindrome_between[start + 1][end - 1])
                        palindrome_between[start][end] = true;
                }

                if(palindrome_between[start][end] && end - (start - 1) > answer.length())
                {
                    longest_palindrome_length = end - (start - 1);
                    answer = s.substr(start, longest_palindrome_length);
                }
            }
        }

        return answer;
    }
};
