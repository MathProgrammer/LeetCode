class Solution {
public:
    int maximumTop(vector<int>& nums, int k) 
    {
        if(nums.size() == 1 && k%2 == 1)
        {
            return -1;
        }
        
        int answer = 0; 
        for(int i = 0; i < nums.size() && i < k - 1; i++)
        {
            answer = max(answer, nums[i]); 
        }
        
        if(k <= nums.size())
        {
            answer = max(answer, nums[k]); 
        }
        
        return answer;
    }
};
