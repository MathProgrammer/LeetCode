class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        
        const int MAX_VALUE = 1001;
        vector <vector <int> > frequency(MAX_VALUE, vector <int> (nums.size() + 1));
        for(int n = 0; n < MAX_VALUE; n++)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                frequency[n][i] = (nums[i] == n) + (i == 0 ? 0 : frequency[n][i - 1]);
            }
        }
        
        const int oo = 2e9;
        vector <int> minimum_cost_till(nums.size() + 1, oo);
        for(int right = 0; right < nums.size(); right++)
        {
            int unique_elements = 0;
            int cost_here = 0;
            for(int left = right; left >= 0; left--)
            {
                int n = nums[left];
                int frequency_here = frequency[n][right] - (left == 0 ? 0 : frequency[n][left - 1]);
                
                if(frequency_here == 1)
                {
                    unique_elements++;
                }
                else if(frequency_here == 2)
                {
                    unique_elements--;
                }
                   
                cost_here = k + (right - left + 1) - unique_elements;
                   
                int cost_of_partitioning_here = (left == 0 ? cost_here : cost_here + minimum_cost_till[left - 1]);
                   
                minimum_cost_till[right] = min(minimum_cost_till[right], cost_of_partitioning_here);
            }
        }
        
        return minimum_cost_till[nums.size() - 1];
    }
};
