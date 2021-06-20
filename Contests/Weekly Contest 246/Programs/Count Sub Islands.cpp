class Solution 
{
    public:
    
    int is_inside(int r, int c, int rows, int columns)
    {
        return (0 <= r && r < rows && 0 <= c && c < columns);
    }
    
    int dfs(int r, int c, vector < vector <int> > &G1, vector < vector <int> > &G2, vector < vector <int> > &V)
    {
        V[r][c] = true; 
        
        const int NO_OF_NEIGHBOURS = 4; 
        int next_x[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1};
        int next_y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};
        
        int good_children = true;
        for(int n = 0; n < NO_OF_NEIGHBOURS; n++)
        {
            int next_r = r + next_x[n];
            int next_c = c + next_y[n];
            
            if(is_inside(next_r, next_c, G1.size(), G1[0].size()) && !V[next_r][next_c] && G2[next_r][next_c] == 1)
            {
                good_children &= dfs(next_r, next_c, G1, G2, V);
            }
        }
        
        return (G1[r][c] == 1 && good_children);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int rows = grid1.size(), columns = grid1[0].size();
        vector <vector <int> > visited(rows, vector <int> (columns, false));
        
        int sub_islands = 0; 
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                if(grid2[r][c] == 1 && !visited[r][c])
                {
                    sub_islands += dfs(r, c, grid1, grid2, visited);
                }
            }
        }
        
        return sub_islands;
    }
};
