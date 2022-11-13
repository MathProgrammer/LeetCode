class Solution {
public:
    
    int lcm(int a, int b)
    {
        return (a*b)/__gcd(a,b);
    }
    int subarrayLCM(vector<int>& nums, int k) {
        
        int answer = 0;
        for(int left = 0; left < nums.size(); left++)
        {
            int subarray_lcm = 1;
            for(int right = left; right < nums.size(); right++)
            {
                if(k%nums[right] != 0)
                {
                    break;
                }
                
                subarray_lcm = lcm(subarray_lcm, nums[right]);
                
                if(subarray_lcm == k)
                {
                    answer++;
                }
            }
        }
        
        return answer;
    }
};
