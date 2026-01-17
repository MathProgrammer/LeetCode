#include <set> 

using namespace std; 

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) 
    {
        set <int> operations; 
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != target[i])
            {
                operations.insert(nums[i]);
            }
        }
        return operations.size();
    }
};