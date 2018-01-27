#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int no_of_strings = strs.size();

        vector <int> zeroes(no_of_strings, 0);
        vector <int> ones(no_of_strings, 0);

        for(int i = 0; i < no_of_strings; i++)
        {
            for(int j = 0; j < strs[i].size(); j++)
            {
                zeroes[i] += (strs[i][j] == '0');
                ones[i]   += (strs[i][j] == '1');
            }
        }

        int max_strings[m + 1][n + 1];
        memset(max_strings, 0, sizeof(max_strings));

        for(int i = 0; i < no_of_strings; i++)
        {
            for(int zero = m; zero >= zeroes[i]; zero--)
            {
                for(int one = n; one >= ones[i]; one--)
                {
                    if(i == 0)
                    {
                        max_strings[zero][one] = 1;
                    }
                    else
                    {
                        max_strings[zero][one] = max(max_strings[zero][one], 1 + max_strings[zero - zeroes[i]][one - ones[i]]);
                    }
                }
            }
        }

        if(no_of_strings == 0)
            return 0;

        return max_strings[m][n];
    }
};

