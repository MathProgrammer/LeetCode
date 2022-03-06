class Solution {
public:
    
    long long sum_till(long long n)
    {
        return (n*(n + 1))/2;
    }
    
    long long segment_sum(long long L, long long R)
    {
        return sum_till(R) - sum_till(L - 1);
    }
    
    long long minimalKSum(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        
        long long answer = 0;
        int last = 1; 
        for(int i = 0; i <= nums.size() && k > 0; i++)
        {  
            int left = last, right;
            if(i == nums.size())
            {
                right = last + k - 1;
            }
            else 
            {
                right = min(nums[i] - 1, last + k - 1);
            }
            
            if(left <= right)
            {
                answer += segment_sum(left, right);
                k -= (right - left + 1); 
            }
            
            if(i < nums.size())
            {
                last = nums[i] + 1;
            }
        }
        
        return answer;
    }
};
