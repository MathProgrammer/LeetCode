#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {

        vector <int> minimum_sum_starting_from_column(triangle.size());

        for(int row = triangle.size() - 1; row >= 0; row--)
        {
            for(int column = 0; column < triangle[row].size(); column++)
            {
                if(row == triangle.size() - 1)
                    minimum_sum_starting_from_column[column] = triangle[row][column];
                else
                    minimum_sum_starting_from_column[column] = triangle[row][column] + min(minimum_sum_starting_from_column[column],
                                                                                            minimum_sum_starting_from_column[column + 1]);
            }
        }
        return minimum_sum_starting_from_column[0];
    }
};
