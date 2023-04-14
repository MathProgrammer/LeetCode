class Solution {
public:
    
    int inside(int r, int c, int rows, int columns)
    {
        return (0 <= r && r < rows && 0 <= c && c < columns);
    }
    
    int minimumObstacles(vector<vector<int>>& grid) {
        const int oo = 1e9;
        int rows = grid.size(), columns = grid[0].size();
        vector <vector <int> > minimum_obstacles(rows, vector <int> (columns, oo));
        minimum_obstacles[0][0] = grid[0][0];
        queue <pair <int, int> > Q;
        Q.push(make_pair(0, 0));
        
        const int NO_OF_NEIGHBOURS = 4;
        int next_x[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1}, next_y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};
        while(Q.size() > 0)
        {
            int x = Q.front().first, y = Q.front().second;
            Q.pop();
            
            for(int n = 0; n < NO_OF_NEIGHBOURS; n++)
            {
                int new_x = x + next_x[n], new_y = y + next_y[n];
                
                if(inside(new_x, new_y, rows, columns))
                {
                    if(minimum_obstacles[x][y] + grid[new_x][new_y] < minimum_obstacles[new_x][new_y])
                    {
                        minimum_obstacles[new_x][new_y] = minimum_obstacles[x][y] + grid[new_x][new_y];
                        Q.push(make_pair(new_x, new_y));
                    }
                }
            }
        }
    
        return minimum_obstacles[rows - 1][columns - 1];
    }
};
