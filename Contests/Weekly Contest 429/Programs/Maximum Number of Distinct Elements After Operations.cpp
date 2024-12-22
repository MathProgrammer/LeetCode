#include <algorithm> 
#include <vector>
#include <set>

using namespace std; 

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        set <int> distinct; 
        for(int i = 0; i < nums.size(); i++)
        {
            int next = nums[i] - k;
            if(distinct.size() > 0)
            {
                next = max(next, *(distinct.rbegin()) + 1);
            }

            next = min(next, nums[i] + k);
            distinct.insert(next);
        }

        return distinct.size();
    }
};