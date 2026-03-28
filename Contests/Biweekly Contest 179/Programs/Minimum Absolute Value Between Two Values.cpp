#include <vector> 
#include <algorithm> 

using namespace std; 

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) 
    {
        int answer = nums.size() + 5;
        int last_1 = -1, last_2 = -1; 
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                last_1 = i;
            }
            else if(nums[i] == 2)
            {
                last_2 = i;
            }

            if(last_1 != -1 && last_2 != -1)
            {
                answer = min(answer, abs(last_1 - last_2));
            }
        }

        if(answer > nums.size())
        {
            answer = -1;
        }

        return answer;
    }
};