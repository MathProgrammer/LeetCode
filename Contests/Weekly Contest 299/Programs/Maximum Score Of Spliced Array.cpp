class Solution {
public:
    
    int check(vector <int> &A, vector <int> &B)
    {
        vector <int> D(A.size());
        for(int i = 0; i < A.size(); i++)
        {
            D[i] = A[i] - B[i];
        }
        
        int maximum_sum = 0;
        vector <int> max_subarray_sum(D.size(), 0);
        for(int i = 0; i < D.size(); i++)
        {
            if(i == 0)
            {
                max_subarray_sum[i] = D[i];
                continue;
            }
            
            max_subarray_sum[i] = max(D[i], max_subarray_sum[i - 1] + D[i]);
            
            maximum_sum = max(maximum_sum, max_subarray_sum[i]);
        }
        
        int answer = maximum_sum;
        for(int i = 0; i < B.size(); i++)
        {
            answer += B[i];
        }
        
        return answer;
        
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) 
    {
        return max(check(nums1, nums2), check(nums2, nums1));    
    }
};
