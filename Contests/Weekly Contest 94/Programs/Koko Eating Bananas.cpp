#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    int ceil(int numerator, int denominator)
    {
        return (numerator/denominator + (numerator%denominator != 0));
    }

    int time(vector <int> &piles, int speed)
    {
        int total_time = 0;

        for(int i = 0; i < piles.size(); i++)
        {
            total_time += ceil(piles[i], speed);
        }

        return total_time;
    }

    int minEatingSpeed(vector<int>& piles, int hours)
    {
        int left_speed = 1, right_speed = 1e9;

        while(left_speed <= right_speed)
        {
            int mid_speed = (left_speed + right_speed) >> 1;

            if(time(piles, mid_speed) <= hours)
            {
                if(mid_speed == left_speed || time(piles, mid_speed - 1) > hours)
                {
                    return mid_speed;
                }
                else
                {
                    right_speed = mid_speed - 1;
                }
            }
            else
            {
                left_speed = mid_speed + 1;
            }
        }
    }
};
