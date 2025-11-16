#include <algorithm> 
#include <string> 

using namespace std; 

class Solution {
public:
    int minLengthAfterRemovals(string s) 
    {
        int as = 0, bs = 0; 
        for(int i = 0; i < s.size(); i++)
        {
            as += (s[i] == 'a');
            bs += (s[i] == 'b');
        }

        int common = min(as, bs); 
        int remaining = s.size() - 2*common;
        return remaining;
    }
};