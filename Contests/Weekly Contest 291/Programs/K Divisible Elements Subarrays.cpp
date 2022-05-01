class Solution {
public:
    
    int countDistinct(vector<int>& nums, int k, int p) 
    {
        int answer = 0;
        const int MOD = 1e9 + 7, MAX_N = 201;
        vector <long long> hash_from(nums.size()), count_from(nums.size());
        
        for(int length = 1; length <= nums.size(); length++)
        {
            set <long long> hash_of_this_length;
            for(int left = 0, right = left + length - 1; right < nums.size(); left++, right++)
            {
                if(nums[right]%p == 0)
                {
                    count_from[left]++;
                }
                
                if(count_from[left] <= k)
                {
                    hash_from[left] = (hash_from[left]*MAX_N + nums[right])%MOD;
                    hash_of_this_length.insert(hash_from[left]);
                }
            }
            
            answer += hash_of_this_length.size();
        }
        
        return answer;
    }
};
