#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        vector <int> no_of_ways_to_climb(n + 1, 0);

        no_of_ways_to_climb[1] = 1;
        no_of_ways_to_climb[2] = 2;

        for(int i = 3; i <= n; i++){
            no_of_ways_to_climb[i] = no_of_ways_to_climb[i - 1] + no_of_ways_to_climb[i - 2];
        }

        return no_of_ways_to_climb[n];
    }
};
