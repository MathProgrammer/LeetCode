class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) 
    {
        vector <int> A(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < k)
            {
                A[i] = -1;
            }
            else if(nums[i] > k)
            {
                A[i] = 1;
            }
            else 
            {
                A[i] = 0;
            }
        }
        
        int answer = 0, is_prefix = true;
        vector <int> sum(A.size() + 1, 0);
        map <int, int> prefix_frequency;
        map <int, int> suffix_frequency;
        prefix_frequency[0] = 1;
        for(int i = 0; i < A.size(); i++)
        {
            sum[i] = A[i] + (i > 0 ? sum[i - 1] : 0);
            
            if(A[i] == 0)
            {
                is_prefix = false; 
            }
            
            if(is_prefix)
            {
                prefix_frequency[sum[i]]++; 
            }
            else 
            {
                suffix_frequency[sum[i]]++;
                
                answer += prefix_frequency[sum[i] - 1] + prefix_frequency[sum[i]];
            } 
        }
        
        return answer;
    }
};
