#include <vector> 
#include <set> 
#include <string> 

using namespace std; 
class Solution 
{
    public:
    long long maximumScore(vector<int>& nums, string s) 
    {
        long long score = 0; 
        multiset <int> M;
        for(int i = 0; i < nums.size(); i++)
        {
            M.insert(nums[i]);

            if(s[i] == '1')
            {
                int largest = *M.rbegin(); 
                M.erase(M.find(largest));

                score += largest;
            }
        }

        return score;
    }
};