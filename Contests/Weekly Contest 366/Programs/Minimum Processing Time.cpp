#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {

        sort(tasks.begin(), tasks.end());
        reverse(tasks.begin(), tasks.end());

        sort(processorTime.begin(), processorTime.end());

        int time = 0;
        for(int p = 0, i = 0; p < processorTime.size(); p++, i += 4)
        {
            int time_here = processorTime[p] + tasks[i];

            time = max(time, time_here);
        }

        return time;
    }
};
