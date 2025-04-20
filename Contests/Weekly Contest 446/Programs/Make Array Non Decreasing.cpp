#include <stack> 
#include <vector>

using namespace std; 

class Solution {
    public:
        int maximumPossibleSize(vector<int>& nums) 
        {
            stack <int> S;
            for(int n : nums)
            {
                if(S.empty() || n >= S.top())
                {
                    S.push(n);
                }
            }
    
            return S.size();
        }
    };