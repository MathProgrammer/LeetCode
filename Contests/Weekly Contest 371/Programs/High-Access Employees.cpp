#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times)
    {
        map <string, vector <string> > access_time_for;
        for(int i = 0; i < access_times.size(); i++)
        {
            string name = access_times[i][0], time = access_times[i][1];
            access_time_for[name].push_back(time);
        }

        vector <string> high_access;
        for(auto it = access_time_for.begin(); it != access_time_for.end(); it++)
        {
            string name = it->first;
            vector <string> time = it->second;
            sort(time.begin(), time.end());

            for(int i = 2; i < time.size(); i++)
            {
                int hour_2 = 10*(time[i][0] - '0') + (time[i][1] - '0');
                int hour_1 = 10*(time[i - 2][0] - '0') + (time[i - 2][1] - '0');
                int hour_difference = hour_2 - hour_1;

                int minute_2 = 10*(time[i][2] - '0') + (time[i][3] - '0');
                int minute_1 = 10*(time[i - 2][2] - '0') + (time[i - 2][3] - '0');
                //Assume they are in different hours.
                int minute_difference = 60 - minute_1 + minute_2;

                if(hour_difference == 0 || (hour_difference == 1 && minute_difference < 60))
                {
                    high_access.push_back(name);
                    break;
                }
            }
        }

        return high_access;
    }
};
