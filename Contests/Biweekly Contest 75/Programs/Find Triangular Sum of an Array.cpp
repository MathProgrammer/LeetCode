class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector <vector <long long> > choose(n, vector <long long> (n, 0)); 
        for(int i = 0; i < n; i++)
        {
            for(int r = 0; r <= i; r++)
            {
                if(i == 0 || r == 0)
                {
                    choose[i][r] = 1;
                    continue;
                }
                else 
                {
                    choose[i][r] = (choose[i - 1][r] + choose[i - 1][r - 1])%10;
                }
            }
        }
        
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            long long contribution = choose[n - 1][i];
            sum += (contribution*1LL*nums[i]);
            sum %= 10;
        }
        
        return sum;
    }
};
