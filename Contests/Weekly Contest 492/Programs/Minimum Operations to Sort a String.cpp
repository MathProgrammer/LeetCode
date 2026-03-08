#include <algorithm> 
#include <string> 

using namespace std; 

class Solution {
public:
    int minOperations(string s) 
    {
        string sorted_s = s; 
        sort(sorted_s.begin(), sorted_s.end()); 

        const int NOT_POSSIBLE = -1;
        if(s.size() == 2 && s != sorted_s)
        {
            return NOT_POSSIBLE;
        }

        if(s == sorted_s)
        {
            return 0;
        }

        if(s[0] == sorted_s[0] || s.back() == sorted_s.back())
        {
            return 1;
        }

        int only_one_start = (sorted_s[0] != sorted_s[1]); 
        int only_one_finish = (sorted_s[s.size() - 1] != sorted_s[s.size() - 2]);
        if(s[0] == sorted_s.back() 
           && s.back() == sorted_s[0] 
           && only_one_start
           && only_one_finish)
        {
            return 3;
        }

        return 2; 
    }
};