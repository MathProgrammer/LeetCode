#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string S)
    {
        int last_zero = S.size() - 1;
        while(last_zero >= 0 && S[last_zero] != '0')
        {
            last_zero--;
        }

        int first_one = 0;
        while(first_one < S.size() && S[first_one] != '1')
        {
            first_one++;
        }

        long long moves = 0;
        while(first_one < last_zero)
        {
            swap(S[first_one], S[last_zero]);
            moves += last_zero - first_one;

            while(last_zero >= 0 && S[last_zero] != '0')
            {
                last_zero--;
            }

            while(first_one < S.size() && S[first_one] != '1')
            {
                first_one++;
            }
        }

        return moves;
    }
};
