#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> no_of_1s_in;

        for(int i = 0; i <= num; i++)
        {
            if(i <= 1)
                no_of_1s_in.push_back(i);
            else
                no_of_1s_in.push_back(no_of_1s_in[i >> 1] + i%2);
        }

        return no_of_1s_in;
    }
};
