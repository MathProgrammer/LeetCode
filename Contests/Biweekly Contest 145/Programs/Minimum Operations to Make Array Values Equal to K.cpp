#include <set> 

using namespace std; 

class Solution 
{
    public:
    int minOperations(vector<int>& nums, int k) 
    {
        set <int> S; 
        for(int n : nums)
        {
            S.insert(n);
        }

        int answer;
        if(*S.begin() < k)
        {
            answer = -1;
        }
        else if(*S.begin() == k)
        {
            answer = S.size() - 1;
        }
        else if(k < *S.begin())
        {
            answer = S.size();
        }
        
        return answer;
    }
};