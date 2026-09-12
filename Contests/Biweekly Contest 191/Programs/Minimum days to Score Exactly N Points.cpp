#include <vector> 

using namespace std; 

class Solution {
public:
    int minDays(int n) 
    {
        vector <int> minimum_days(n + 1, n + 1); 
        minimum_days[0] = 0;
        for(int i = 1, t = 1; t <= n; i++, t += i)
        {
            minimum_days[t] = i;
        }

        minimum_days[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1, t = 1; t <= i; j++, t += j)
            {
                minimum_days[i] = min(minimum_days[i], minimum_days[i - t] + 1 + j);
            }
        }

        return minimum_days[n];
    }
};