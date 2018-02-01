#include <bits/stdc++.h>

using namespace std;

class Solution
{

    public:
    int findLength(vector<int>& A, vector<int>& B)
    {
        int common_subarray[A.size() + 1][B.size() + 1];

        int longest_repeating_subarray = 0;

        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < B.size(); j++)
            {
                if(i == 0 || j == 0)
                {
                    common_subarray[i][j] = (A[i] == B[j]);
                }
                else
                {
                    common_subarray[i][j] = (A[i] == B[j] ? 1 + common_subarray[i - 1][j - 1] : 0);
                }

                longest_repeating_subarray = max(longest_repeating_subarray, common_subarray[i][j]);
            }
        }

        return longest_repeating_subarray;
    }
};
