#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int no_of_elements = nums.size();
        const int oo = 1e9;
        vector <int> max_jumps_from(no_of_elements, -oo);
        max_jumps_from[no_of_elements - 1] = 0;
        for(int i = no_of_elements - 2; i >= 0; i--)
        {
            for(int j = i + 1; j <= no_of_elements - 1; j++)
            {
                if(-target <= nums[j] - nums[i] && nums[j] - nums[i] <= target && max_jumps_from[j] != -oo)
                {
                    max_jumps_from[i] = max(max_jumps_from[i], 1 + max_jumps_from[j]);
                }
            }
        }

        return (max_jumps_from[0] == -oo ? -1 : max_jumps_from[0]);
    }
};
