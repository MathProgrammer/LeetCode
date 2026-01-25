#include <vector> 

using namespace std; 

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) 
    {
        int answer = 0, is_increasing = true; 
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] >= nums[i + 1])
            {
                answer = i + 1;
                break;
            }
        }

        return answer;
    }
};