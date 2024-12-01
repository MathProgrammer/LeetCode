class Solution {
public:
    int getLargestOutlier(vector<int>& nums) 
    {
        map <int, int> frequency;
        sort(nums.begin(), nums.end()); 
        int sum = 0; 
        for(int num : nums)
        {
            sum += num;
            frequency[num]++;
        }
        
        int largest_outlier = -1; 
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            int sum_without_this = sum - nums[i];
            
            frequency[nums[i]]--;
            
            if(sum_without_this%2 == 0 && frequency[sum_without_this/2] >= 1)
            {
                largest_outlier = nums[i]; 
                break;
            }
            
            frequency[nums[i]]++;
        }
        
        return largest_outlier;
    }
};