#include <bits/stdc++.h>

using namespace std;


static const int MAX_M = 100, MAX_N = 100, MAX_STRINGS = 600;
int max_strings[MAX_STRINGS + 1][MAX_M + 1][MAX_N + 1];

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

        memset(max_strings, 0, sizeof(max_strings));

        for(int i = 0; i < no_of_strings; i++)
        {
            for(int zero = 0; zero <= m; zero++)
            {
                for(int one = 0; one <= n; one++)
                {
                    if(i == 0)
                    {
                        max_strings[i][zero][one] = (zero >= zeroes[i] && one >= ones[i] ? 1 : 0);
                    }
                    else
                    {
                        max_strings[i][zero][one] = max_strings[i - 1][zero][one];

                        if(zero >= zeroes[i] && one >= ones[i])
                            max_strings[i][zero][one] = max(max_strings[i][zero][one], 1 + max_strings[i - 1][zero - zeroes[i]][one - ones[i]]);
                    }
                }
            }
        }

        if(no_of_strings == 0)
            return 0;

        return max_strings[no_of_strings - 1][m][n];
    }
};
