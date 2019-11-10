#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    void dfs(int i, int j, vector <vector <int> >&grid, vector <vector <int> >&visited, int &no_borders)
    {
        if(grid[i][j] == 1 || visited[i][j])
        {
            return;
        }

        if(i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1)
        {
            no_borders = false;
            return;
        }

        visited[i][j] = true;

        const int NO_OF_NEIGHBOURS = 4;
        int next_i[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1}, next_j[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};
        for(int n = 0; n < NO_OF_NEIGHBOURS; n++)
        {
            dfs(i + next_i[n], j + next_j[n], grid, visited, no_borders);
        }
    }

    int closedIsland(vector< vector<int> >& grid)
    {
        int rows = grid.size(), columns = grid[0].size();

        int good_components = 0;
        vector <vector <int> > visited(rows, vector <int> (columns, false));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                int no_borders = true;
                if(grid[i][j] == 0 && !visited[i][j])
                {
                    dfs(i, j, grid, visited, no_borders);

                    good_components += (no_borders == true);
                }
            }
        }

        return good_components;
    }
};
