#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {

        typedef vector <int> v_int;
        vector <v_int> minimum_sum_starting_from(triangle.size(), v_int(triangle.size(), 0));

        for(int row = triangle.size() - 1; row >= 0; row--)
        {
            for(int column = 0; column < triangle[row].size(); column++)
            {
                if(row == triangle.size() - 1)
                    minimum_sum_starting_from[row][column] = triangle[row][column];
                else
                    minimum_sum_starting_from[row][column] = triangle[row][column] + min(minimum_sum_starting_from[row + 1][column],
                                                                       minimum_sum_starting_from[row + 1][column + 1]);
            }
        }
        return minimum_sum_starting_from[0][0];
    }
};
