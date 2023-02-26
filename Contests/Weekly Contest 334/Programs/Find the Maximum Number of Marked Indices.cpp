class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int marked = 0;
        
        for(int i = 0, j = nums.size()/2; i < nums.size()/2 && j < nums.size(); j++)
        {
            if(2*nums[i] <= nums[j])
            {
                marked += 2;
                i++;
            }
        }
        
        return marked;
    }
};
