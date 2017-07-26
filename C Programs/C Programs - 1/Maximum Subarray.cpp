#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_subarray_sum = nums[0];
        int max_subarray_sum_till = 0;

        for(unsigned int i = 0; i < nums.size(); i++)
        {
            max_subarray_sum_till = max(max_subarray_sum_till + nums[i], nums[i]) ;
            max_subarray_sum = max(max_subarray_sum, max_subarray_sum_till);
        }

        return max_subarray_sum;

    }
};
