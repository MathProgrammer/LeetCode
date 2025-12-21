#include <algorithm> 

using namespace std; 

class Solution 
{
    private: 
    int reverse(int n)
    {
        int answer = 0; 
        while(n > 0)
        {
            int digit = n%10; 
            answer = answer*10 + digit; 
            n /= 10;
        }

        return answer;
    }
    
    public:
    int mirrorDistance(int n) 
    {
        return abs(n - reverse(n));    
    }
};