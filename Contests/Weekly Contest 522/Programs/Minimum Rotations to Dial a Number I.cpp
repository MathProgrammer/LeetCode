#include <algorithm> 
#include <string> 

using namespace std; 

class Solution {
public:
    int minRotations(string s) 
    {
        int current = 0, prefix_steps = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int steps_here = abs(current - (s[i] - '0'));
            steps_here = min(steps_here, 10 - steps_here);
            
            prefix_steps += steps_here;
            current = s[i] - '0';
        }    

        return prefix_steps;
    }
};