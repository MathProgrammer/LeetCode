#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        sort(capacity.begin(), capacity.end());
        reverse(capacity.begin(), capacity.end());

        int total_apples = 0;
        for(int i = 0; i < apple.size(); i++)
        {
            total_apples += apple[i];
        }

        int used_boxes = 1;
        for(int i = 0, total_capacity = 0; i < capacity.size(); i++, used_boxes++)
        {
            total_capacity += capacity[i];
            if(total_capacity >= total_apples)
            {
                break;
            }
        }

        return used_boxes;
    }
};
