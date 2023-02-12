class Solution {
public:
    long long countFairPairs(vector<int>& nums, int L, int R) {
        sort(nums.begin(), nums.end());
        
        long long answer = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int pairs_from_i = 0;
            
            int last_j_in_range = upper_bound(nums.begin() + i, nums.end(), R - nums[i]) - nums.begin() - 1;
            if(last_j_in_range > i)
            {
                pairs_from_i += (last_j_in_range - i);
            }
            
            int last_j_before_range = upper_bound(nums.begin() + i, nums.end(), L - nums[i] - 1) - nums.begin() - 1;
            if(last_j_before_range > i)
            {
                pairs_from_i -= (last_j_before_range - i);
            }
            
            answer += pairs_from_i;
            
        }
        
        return answer;
    }
};
