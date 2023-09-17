#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int answer = (0 < nums[0]) + (nums.back() < nums.size());
        for(int i = 0; i + 1 < nums.size(); i++)
        {
            int prefix = i + 1;
            if(nums[i] < prefix && prefix < nums[i + 1])
            {
                answer++;
            }
        }
        return answer;
    }
};

