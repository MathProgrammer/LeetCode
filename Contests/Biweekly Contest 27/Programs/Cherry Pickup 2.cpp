class Solution {
public:

    int inside(int x, int left, int right)
    {
        return (left <= x && x <= right);
    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        int rows = grid.size(), columns = grid[0].size();
        int maximum_from[rows][columns][columns];
        for(int r = rows - 1; r >= 0; r--)
        {
            for(int c1 = 0; c1 < columns; c1++)
            {
                for(int c2 = c1 + 1; c2 < columns; c2++)
                {
                    maximum_from[r][c1][c2] = grid[r][c1] + grid[r][c2];

                    if(r == rows - 1)
                    {
                        continue;
                    }

                    for(int next_c1 = c1 - 1; next_c1 <= c1 + 1; next_c1++)
                    {
                        for(int next_c2 = c2 - 1; next_c2 <= c2 + 1; next_c2++)
                        {
                            if(!inside(next_c1, 0, columns - 1) || 
                               !inside(next_c2, 0, columns - 1) || 
                               next_c1 >= next_c2)
                               {
                                   continue;
                               }

                            maximum_from[r][c1][c2] = max(maximum_from[r][c1][c2], 
                                grid[r][c1] + grid[r][c2] + 
                                maximum_from[r + 1][next_c1][next_c2]);
                        }
                    }
                }
            }
        }

        return maximum_from[0][0][columns - 1];
    }
};
