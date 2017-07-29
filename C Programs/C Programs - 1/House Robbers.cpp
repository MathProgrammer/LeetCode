#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        vector <int> maximum_loot(nums.size(), 0);

        for(unsigned int house_i = 0; house_i < nums.size(); house_i++)
        {
            if(house_i == 0)
                maximum_loot[house_i] = nums[house_i];
            else if(house_i == 1)
                maximum_loot[house_i] = max(nums[house_i], maximum_loot[house_i - 1]);
            else
                maximum_loot[house_i] = max(nums[house_i] + maximum_loot[house_i - 2], maximum_loot[house_i - 1]);
        }

        return maximum_loot[nums.size() - 1];

    }
};
