#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int deleteAndEarn(vector<int>& nums)
    {
        const int MAX = 1e4;
        vector <int> frequency(MAX + 1, 0);

        for(int i = 0; i < nums.size(); i++)
            frequency[nums[i]]++;

        vector <int> max_score_till(MAX + 1, 0);
        for(int i = 1; i <= MAX; i++)
        {
            if(i <= 2)
            {
                max_score_till[i] = max(i*frequency[i], (i - 1)*frequency[i - 1]);
                continue;
            }

            int delete_i_points = i*frequency[i] + max_score_till[i - 2];
            int delete_i_minus_1_points = (i - 1)*frequency[i - 1] + max_score_till[i - 3];

            max_score_till[i] = max(delete_i_points, delete_i_minus_1_points);
        }

        return max_score_till[MAX];
    }
};
