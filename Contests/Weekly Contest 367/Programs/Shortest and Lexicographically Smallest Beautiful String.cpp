#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string answer;
        for(int l = 0; l < s.size(); l++)
        {
            string current;
            int no_of_1s = 0;
            for(int r = l; r < s.size(); r++)
            {
                current += s[r];
                no_of_1s += (s[r] == '1');

                if(no_of_1s == k)
                {
                    if(answer.size() == 0 || current.size() < answer.size() ||
                       (current.size() == answer.size() && current < answer) )
                    {
                        answer = current;
                    }

                    break;
                }
            }
        }

        return answer;
    }
};
