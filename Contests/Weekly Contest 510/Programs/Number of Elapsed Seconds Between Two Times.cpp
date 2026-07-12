#include <string> 

using namespace std; 

class Solution 
{
public:
    int get_hour(string S)
    {
        return (S[0] - '0')*10 + (S[1] - '0');
    }

    int get_min(string S)
    {
        return (S[3] - '0')*10 + (S[4] - '0');
    }

    int get_s(string S)
    {
        return (S[6] - '0')*10 + (S[7] - '0');
    }
    
    int secondsBetweenTimes(string startTime, string endTime) 
    {
        const int SECONDS_IN_HOUR = 60*60, SECONDS_IN_MIN = 60;
        int t1 = get_hour(endTime)*SECONDS_IN_HOUR + get_min(endTime)*SECONDS_IN_MIN + get_s(endTime); 
        int t2 = get_hour(startTime)*SECONDS_IN_HOUR + get_min(startTime)*SECONDS_IN_MIN + get_s(startTime); 
        return t1- t2;
    }
};