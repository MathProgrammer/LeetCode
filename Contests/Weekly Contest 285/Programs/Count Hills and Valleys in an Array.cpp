class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        vector <int> A; 
        A.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != A.back())
            {
                A.push_back(nums[i]);
            }
        }
        
        int answer = 0;
        for(int i = 1; i + 1 < A.size(); i++)
        {
            if( (A[i - 1] < A[i] && A[i + 1] < A[i]) || 
                (A[i] < A[i - 1] && A[i] < A[i + 1]) )
            {
                answer++;
            }
        }
        
        return answer;
    }
};
