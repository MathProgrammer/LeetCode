#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        typedef vector <int> v_int;
        vector <v_int> no_of_ways_to_reach(n + 1, v_int(m + 1, 0));

        for(int i =  1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(i == 1 || j == 1)
                    no_of_ways_to_reach[i][j] = 1;
                else
                    no_of_ways_to_reach[i][j] = no_of_ways_to_reach[i - 1][j] + no_of_ways_to_reach[i][j - 1];

        return no_of_ways_to_reach[n][m];
    }
};
