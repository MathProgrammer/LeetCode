#include <algorithm> 
#include <vector> 

using namespace std; 

class Solution {
public:
    int absDifference(vector<int>& nums, int k) 
    {
        long long sum = 0;
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i < k; i++)
        {
            sum -= nums[i];
        }

        reverse(nums.begin(), nums.end()); 
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        return sum;
    }
};