#include <algorithm> 
#include <vector> 

using namespace std; 

class Solution {
public:
    int minRotations(int n, string s) 
    {
        vector <int> prefix_steps(s.size() + 1); 
        int current = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int steps_here = abs(current - (s[i] - '0'));
            steps_here = min(steps_here, 10 - steps_here);
            
            prefix_steps[i] = (i == 0 ? 0 : prefix_steps[i - 1]) + steps_here;
            current = s[i] - '0';
        }
        
        current = s[s.size() - 1] - '0';
        vector <int> suffix_steps(s.size() + 5);
        for(int i = s.size() - 2; i >= 0; i--)
        {
            int steps_here = abs(current - (s[i] - '0'));
            steps_here = min(steps_here, 10 - steps_here);
            
            suffix_steps[i] = suffix_steps[i + 1] + steps_here;
            current = s[i] - '0';
        }

        int entire_prefix = prefix_steps[s.size() - 1]; 
        int steps_for_last = abs('0' - s.back()); 
        steps_for_last = min(steps_for_last, 10 - steps_for_last);
        int entire_suffix = steps_for_last + suffix_steps[0];
        int answer = min(entire_prefix, entire_suffix); 
        for(int i = 0; i + 1 < s.size(); i++)
        {
            int steps_here = abs(s[i] - s.back()); 
            steps_here = min(steps_here, 10 - steps_here); 
            
            answer = min(answer, prefix_steps[i] + steps_here + suffix_steps[i + 1]);
        }

        return answer;
    }
};