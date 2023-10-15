#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector <int> suffix_minimum_index(nums.size()), suffix_maximum_index(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i == nums.size() - 1)
            {
                suffix_minimum_index[i] = suffix_maximum_index[i] = i;
                continue;
            }

            int previous_minimum = nums[suffix_minimum_index[i + 1]], previous_maximum = nums[suffix_maximum_index[i + 1]];
            suffix_minimum_index[i] = (nums[i] < previous_minimum ? i : suffix_minimum_index[i + 1]);
            suffix_maximum_index[i] = (nums[i] > previous_maximum ? i : suffix_maximum_index[i + 1]);
        }

        vector <int> answer(2, -1);
        for(int i = 0; i + indexDifference < nums.size(); i++)
        {
            int suffix = i + indexDifference;
            int suffix_max =  nums[suffix_maximum_index[suffix]], suffix_min = nums[suffix_minimum_index[suffix]];

            if(abs(nums[i] - suffix_max) >= valueDifference)
            {
                answer[0] = i, answer[1] = suffix_maximum_index[suffix];
            }

            if(abs(nums[i] - suffix_min) >= valueDifference)
            {
                answer[0] = i, answer[1] = suffix_minimum_index[suffix];
            }
        }

        return answer;
    }
};
