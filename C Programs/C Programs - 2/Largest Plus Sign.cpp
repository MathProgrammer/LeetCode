#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    typedef vector <int> v_int;

    int min_4(int a, int b, int c, int d)
    {
        return min(min(a, b), min(c, d));
    }

    int orderOfLargestPlusSign(int N, vector<v_int>& mines)
    {
        vector <v_int> grid(N + 2, v_int(N + 2, 0));

        for(int row = 1; row <= N; row++)
            for(int column = 1; column <= N; column++)
                grid[row][column] = 1;

        for(int i = 0; i < mines.size(); i++)
        {
            int row = mines[i][0] + 1, column = mines[i][1] + 1;

            grid[row][column] = 0;
        }

        vector <v_int> up_ones(N + 2, v_int(N + 2, 0));
        vector <v_int> down_ones(N + 2, v_int(N + 2, 0));

        for(int column = 1; column <= N; column++)
        {
            up_ones[0][column] = 0;
            for(int row = 1; row <= N; row++)
                up_ones[row][column] = (grid[row][column] == 1 ? 1 + up_ones[row - 1][column] : 0);

            down_ones[N + 1][column] = 0;
            for(int row = N; row >= 1; row--)
                down_ones[row][column] = (grid[row][column] == 1 ? 1 + down_ones[row + 1][column] : 0);
        }

        vector <v_int> left_ones(N + 2, v_int(N + 2, 0));
        vector <v_int> right_ones(N + 2, v_int(N + 2, 0));

        for(int row = 1; row <= N; row++)
        {
            left_ones[row][0] = 0;
            for(int column = 1; column <= N; column++)
                left_ones[row][column] = (grid[row][column] == 1 ? 1 + left_ones[row][column - 1] : 0);

            right_ones[row][N + 1] = 0;
            for(int column = N; column >= 1; column--)
                right_ones[row][column] = (grid[row][column] == 1 ? 1 + right_ones[row][column + 1] : 0);
        }

        int max_order = 0;

        for(int row = 1; row <= N; row++)
        {
            for(int column = 1; column <= N; column++)
            {
                if(grid[row][column] == 1)
                {
                    int plus_centered_here = 1 + min_4(up_ones[row - 1][column], down_ones[row + 1][column], left_ones[row][column - 1], right_ones[row][column + 1]);
                    max_order = max(max_order, plus_centered_here);
                }
            }
        }

        return max_order;
    }
};
