#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int closest_sum = nums[0] + nums[1] + nums[2];

        sort(all(nums));

        for(unsigned int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            int reduced_target = target - a;

            int pointer_1 = i + 1;
            int pointer_2 = nums.size() - 1;

            while(pointer_1 < pointer_2)
            {
                int b = nums[pointer_1], c = nums[pointer_2];

                if(b + c == reduced_target)
                {
                    closest_sum = a + b + c;

                    pointer_1++;
                    pointer_2--;
                }
                else if(b + c > reduced_target)
                {
                    pointer_2--;
                    if(abs(a + b + c - target) < abs(closest_sum - target))
                        closest_sum = a + b + c;
                }
                else if(b + c < reduced_target)
                {
                    pointer_1++;
                    if(abs(a + b + c - target) < abs(closest_sum - target))
                        closest_sum = a + b + c;
                }
            }
        }

        return closest_sum;
    }
};
