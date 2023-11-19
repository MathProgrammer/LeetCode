#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3)
    {
        int largest_equal_prefix = 0;
        for(int i = 0; i < s1.size() && i < s2.size() && i < s3.size(); i++)
        {
            if(s1[i] == s2[i] && s2[i] == s3[i])
            {
                largest_equal_prefix = i + 1;
            }
            else
            {
                break;
            }
        }

        int answer = -1;
        if(largest_equal_prefix > 0)
        {
            answer = (s1.size() - largest_equal_prefix) + (s2.size() - largest_equal_prefix) + (s3.size() - largest_equal_prefix);
        }

        return answer;
    }
};
