#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    int numDecodings(string s)
    {
        vector <int> no_of_decodings(s.size(), 0);

        for(int i = 0; i < s.size(); i++)
        {
            if(i == 0)
            {
                no_of_decodings[i] = (s[i] > '0' ? 1 : 0);
            }
            else
            {
                no_of_decodings[i] = (s[i] > '0' ? no_of_decodings[i - 1] : 0);

                if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                {
                    if(i == 1)
                        no_of_decodings[i]++;
                    else
                        no_of_decodings[i] += no_of_decodings[i - 2];
                }
            }
        }

        if(s.size() == 0)
            return 0;

        return no_of_decodings[s.size() - 1];
    }
};
