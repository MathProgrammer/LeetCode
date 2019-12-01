#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        vector <int> answer;

        if(tomatoSlices < 2*cheeseSlices || tomatoSlices > 4*cheeseSlices)
        {
            return answer;
        }

        int jumbo = 0;
        while(tomatoSlices > 2*cheeseSlices)
        {
            jumbo++;
            tomatoSlices -= 4;
            cheeseSlices--;
        }

        if(tomatoSlices != 2*cheeseSlices)
        {
            return answer;
        }

        int small = cheeseSlices;

        answer.push_back(jumbo);
        answer.push_back(small);

        return answer;
    }
};
