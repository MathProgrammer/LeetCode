class Solution 
{
    public:
    
    int ceil(int n, int d)
    {
        return (n/d + (n%d != 0 ? 1 : 0));
    }
    
    int possible(int target, vector <int> &A, int operations)
    {
        int operations_used = 0;
        sort(A.begin(), A.end());
        for(int i = A.size() - 1; i >= 0; i--)
        {
            operations_used += ceil(A[i], target) - 1;
        }
        
        return (operations_used <= operations);
    }
    
    int minimumSize(vector<int>& A, int maxOperations) 
    {
        //Penalty <= right and > left
        int left = 0, right = 1e9;
        while(right - left > 1)
        {
            int mid = (left + right)/2;
            
            if(possible(mid, A, maxOperations))
            {
                right = mid;
            }
            else 
            {
                left = mid;
            }
        }
        
        return right;
    }
};
