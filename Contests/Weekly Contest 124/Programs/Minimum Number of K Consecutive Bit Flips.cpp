class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int number_of_flips = 0;
        vector <int> flip_starting(nums.size()), flip_ending(nums.size()), flips_here(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0)
            {
                flips_here[i] = flips_here[i - 1] + flip_starting[i - 1] - flip_ending[i - 1];
                nums[i] = (nums[i] + flips_here[i])%2; 
                
            }
            
            if(nums[i] == 0)
            {
                if(i + k - 1 < nums.size())
                {
                    number_of_flips++;
                    flip_starting[i]++;
                    flip_ending[i + k - 1]++;
                    nums[i] = 1;
                }
            }
        }
        
        const int NOT_POSSIBLE = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                number_of_flips = NOT_POSSIBLE;
            }
        }
        
        return number_of_flips;
    }
};
