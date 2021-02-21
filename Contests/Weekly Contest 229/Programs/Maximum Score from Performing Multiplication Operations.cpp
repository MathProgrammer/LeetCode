class Solution 
{
    public:
    int maximumScore(vector<int>& A, vector<int>& multipliers) 
    {
        int n = A.size();
        int m = multipliers.size();
        
        vector <vector <int> > answer(m + 1, vector <int> (m + 1, 0));
        
        for(int current_multiplier = m - 1; current_multiplier >= 0; current_multiplier--)
        {
            int operations_used = current_multiplier;
            
            for(int left = 0; left <= operations_used; left++)
            {   
                int right = (n - 1) - (operations_used - left); 
                
                if(right < left)
                {
                    continue;
                }
                
                int choosing_left, choosing_right;
                if(current_multiplier == m - 1)
                {
                    choosing_left = multipliers[current_multiplier]*A[left];
                    choosing_right = multipliers[current_multiplier]*A[right];
                }
                else 
                {
                    choosing_left = multipliers[current_multiplier]*A[left] + answer[left + 1][current_multiplier + 1];
                    choosing_right = multipliers[current_multiplier]*A[right] + answer[left][current_multiplier + 1];
                }
                
                answer[left][current_multiplier] = max(choosing_left, choosing_right);
            }
        }
        
        return answer[0][0];
    }
};
