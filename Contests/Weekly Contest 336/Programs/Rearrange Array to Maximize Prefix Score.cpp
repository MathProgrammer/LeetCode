class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        vector <long long> prefix(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            prefix[i] = nums[i];
            if(i > 0)
            {
                prefix[i] += prefix[i - 1];
            }
        }
        
        int score = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            score += (prefix[i] > 0);
        }
        
        return score;
    }
};
