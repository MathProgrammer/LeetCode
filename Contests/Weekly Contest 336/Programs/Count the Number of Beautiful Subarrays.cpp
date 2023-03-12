class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
        long long beautiful_subarrays = 0;
        map <int, int> prefix_frequency;
        prefix_frequency[0] = 1;
        
        vector <int> prefix_xor(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            prefix_xor[i] = nums[i];
            
            if(i > 0)
            {
                prefix_xor[i] ^= prefix_xor[i - 1];
            }
            
            beautiful_subarrays += prefix_frequency[prefix_xor[i]];
            prefix_frequency[prefix_xor[i]]++;
        }
        
        return beautiful_subarrays;
    }
};
