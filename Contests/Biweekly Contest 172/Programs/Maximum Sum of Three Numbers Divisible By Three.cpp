#include <vector> 

using namespace std; 

class Solution 
{
    public:
    #define all(v) (v).begin(), (v).end()
    int maximumSum(vector<int>& nums) 
    {
        vector <vector <int> > mods(3); 
        for(int n : nums)
        {
            mods[n%3].push_back(n);
        }

        const int oo = 1e9;
        
        int maximum_sum = 0; 
        int max_sum_of_each = 0;
        for(int m = 0; m < 3; m++)
        {
            if(mods[m].size() == 0)
            {
                max_sum_of_each = -oo;
                continue;
            }

            sort(all(mods[m]));
            reverse(all(mods[m]));

            max_sum_of_each += mods[m][0];
            
            if(mods[m].size() < 3)
            {
                continue;
            }

            int sum_here = mods[m][0] + mods[m][1] + mods[m][2]; 
            maximum_sum = max(maximum_sum, sum_here);
        }

        maximum_sum = max(maximum_sum, max_sum_of_each);
        
        return maximum_sum;
    }
};