class Solution 
{
    public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) 
    {
        int last_g = 0;
        for(int i = 0; i < nums.size() && last_g < groups.size(); )
        {   
            int matches = true;
            
            for(int j = 0; j < groups[last_g].size(); j++)
            {
                if(nums[i + j] != groups[last_g][j])
                {
                    matches = false;
                    break;
                }
            }
            
            if(matches)
            {
                i += groups[last_g].size();
                
                last_g++;
            }
            else 
            {
                i++;
            }
        }   
            
        return (last_g == groups.size());
    }
};
