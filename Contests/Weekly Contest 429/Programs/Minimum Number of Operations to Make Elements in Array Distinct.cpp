#include <vector> 
#include <map>
using namespace std; 

class Solution 
{
    public:
    int minimumOperations(vector<int>& nums) 
    {
        map <int, int> last; 
        for(int i = 0; i < nums.size(); i++)
        {
            last[nums[i]] = i;
        }

        int last_removable = 0; 
        for(int i = 0; i < nums.size(); i++)
        {
            if(last[nums[i]] != i)
            {
                last_removable = i + 1;
            }
        }

        return last_removable/3 + (last_removable%3 != 0);
    }
};