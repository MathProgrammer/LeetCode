#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {

        typedef vector <int> v_int;
        set <v_int> solution_set;
        vector <v_int> solutions;

        sort(all(nums));

        for(unsigned int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];

            int pointer_1 = i + 1;
            int pointer_2 = nums.size() - 1;

            while(pointer_1 < pointer_2)
            {
                if(nums[pointer_1] + nums[pointer_2] == target)
                {
                    vector <int> triplet(3);
                    triplet[0] = nums[i];
                    triplet[1] = nums[pointer_1];
                    triplet[2] = nums[pointer_2];

                    if(solution_set.count(triplet) == 0)
                    {
                        solution_set.insert(triplet);
                        solutions.push_back(triplet);
                    }
                    pointer_1++;
                    pointer_2--;
                }
                else if(nums[pointer_1] + nums[pointer_2] > target)
                {
                    pointer_2--;
                }
                else if(nums[pointer_1] + nums[pointer_2] < target)
                {
                    pointer_1++;
                }
            }
        }

        return solutions;
    }
};
