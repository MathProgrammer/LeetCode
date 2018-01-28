#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    void shift(string &s)
    {
        s = s + s.back();

        for(int i = s.size() - 1; i >= 1; i--)
            s[i] = s[i - 1];
    }

    int numDecodings(string s)
    {
        int no_of_characters = s.size();
        shift(s);

        const int MOD = 1e9 + 7;
        long long no_of_ways[no_of_characters + 1];
        no_of_ways[0] = 1;

        for(int i = 1; i <= no_of_characters; i++)
        {
            if(i == 1)
            {
                no_of_ways[i] = (s[i] > '0' ? 1 : 0);

                if(s[i] == '*')
                    no_of_ways[i] = 9;
            }
            else
            {
                if(s[i] == '*')
                {
                    no_of_ways[i] = 9*no_of_ways[i - 1];

                    if(s[i - 1] == '1' || s[i - 1] == '*')
                        no_of_ways[i] += 9*no_of_ways[i - 2];

                    if(s[i - 1] == '2' || s[i - 1] == '*')
                        no_of_ways[i] += 6*no_of_ways[i - 2];
                }
                else
                {
                    no_of_ways[i] = (s[i] > '0' ? no_of_ways[i - 1] : 0);

                    if(s[i - 1] == '1' || s[i - 1] == '*')
                        no_of_ways[i] += no_of_ways[i - 2];

                    if((s[i - 1] == '*' || s[i - 1] == '2') && s[i] <= '6')
                        no_of_ways[i] += no_of_ways[i - 2];
                }
            }

            no_of_ways[i] %= MOD;
        }

        if(no_of_characters == 0)
            return 0;

        return no_of_ways[no_of_characters];
    }
};
