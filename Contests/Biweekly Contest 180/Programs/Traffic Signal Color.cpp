#include <string> 

using namespace std; 

class Solution 
{
    public:
    string trafficSignal(int timer) 
    {
        const int INVALID = 91, ORANGE = 30, GREEN = 0;
        if(ORANGE < timer && timer < INVALID)
        {
            return "Red";
        }
        
        if(timer == ORANGE)
        {
            return "Orange";
        }

        if(timer == 0)
        {
            return "Green";
        }

        return "Invalid";
    }
};