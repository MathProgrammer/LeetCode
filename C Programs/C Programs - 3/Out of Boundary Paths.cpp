#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    int is_outside(int x, int y, int max_x, int max_y)
    {
        return (x < 0 || x >= max_x || y < 0 || y >= max_y);
    }

    int findPaths(int rows, int columns, int N, int i, int j)
    {
        const int MOD = 1e9 + 7, NO_OF_NEIGHBOURS = 4;

        long long no_of_paths[rows][columns][N + 1];
        memset(no_of_paths, 0, sizeof(no_of_paths));

        int step_x[4] = {-1, 0, 0, 1};
        int step_y[4] = {0, 1, -1, 0};

        for(int moves = 1; moves <= N; moves++)
        {
            for(int x = 0; x < rows; x++)
            {
                for(int y = 0; y < columns; y++)
                {
                    for(int neighbour = 0; neighbour < NO_OF_NEIGHBOURS; neighbour++)
                    {
                        int neighbour_x = x + step_x[neighbour], neighbour_y = y + step_y[neighbour];

                        if(is_outside(neighbour_x, neighbour_y, rows, columns))
                            no_of_paths[x][y][moves]++;
                        else
                            no_of_paths[x][y][moves] += no_of_paths[neighbour_x][neighbour_y][moves - 1];
                    }

                    no_of_paths[x][y][moves] %= MOD;
                }
            }
        }

        return no_of_paths[i][j][N];
    }
};
