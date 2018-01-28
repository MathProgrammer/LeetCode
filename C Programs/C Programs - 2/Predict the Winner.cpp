#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    bool PredictTheWinner(vector<int>& nums)
    {
        int number_of_elements = nums.size();

        vector <int> sum(number_of_elements, 0);
        for(int i = 0; i < number_of_elements; i++)
            sum[i] = nums[i] + (i > 0 ? sum[i - 1] : 0);

        int max_score[number_of_elements][number_of_elements];

        for(int i = 0; i < number_of_elements; i++)
            max_score[i][i] = nums[i];

        for(int length = 2; length <= number_of_elements; length++)
        {
            for(int start = 0, end = start + (length - 1); end < number_of_elements; start++, end++)
            {
                int take_start = nums[start] + (sum[end] - sum[start] - max_score[start + 1][end]);
                int take_end   = nums[end] + (sum[end - 1] - sum[start - 1] - max_score[start][end - 1]);

                max_score[start][end] = max(take_start, take_end);
            }
        }

        return (2*max_score[0][number_of_elements - 1] >= sum[number_of_elements - 1]);
    }
};
