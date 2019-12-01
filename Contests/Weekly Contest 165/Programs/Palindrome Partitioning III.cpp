#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int palindromePartition(string S, int k)
    {
        vector <vector <int> > steps_to_palindrome(S.size() + 1, vector <int> (S.size() + 1, 0));
        for(int length = 1; length <= S.size(); length++)
        {
            for(int left = 0, right = left + length - 1; right < S.size(); left++, right++)
            {
                if(length == 1)
                {
                    steps_to_palindrome[left][right] = 0;
                    continue;
                }
                else if(length == 2)
                {
                    steps_to_palindrome[left][right] = (S[left] == S[right] ? 0 : 1);
                    continue;
                }

                steps_to_palindrome[left][right] = (S[left] != S[right]) + steps_to_palindrome[left + 1][right - 1];
            }
        }

        const int oo = 1e9;
        vector <vector <int> > minimum_steps(S.size() + 1, vector <int> (k + 1, oo));
        for(int i = 0; i < S.size(); i++)
        {
            for(int parts = 1; parts <= k; parts++)
            {
                if(parts == 1)
                {
                    minimum_steps[i][parts] = steps_to_palindrome[0][i];
                    continue;
                }

                for(int j = i - 1; j >= 0; j--)
                {
                    minimum_steps[i][parts] = min(minimum_steps[i][parts], steps_to_palindrome[j + 1][i] + minimum_steps[j][parts - 1]);
                }
            }
        }
        
        return minimum_steps[S.size() - 1][k];
    }
};

