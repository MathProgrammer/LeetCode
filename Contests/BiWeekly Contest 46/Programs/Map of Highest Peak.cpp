class Solution 
{
    public:
    
    int is_inside(int x, int y, int R, int C)
    {
        return (0 <= x && x < R && 0 <= y && y < C);
    }
    
    vector < vector<int> > highestPeak(vector< vector<int> > &isWater) 
    {
        int rows = isWater.size(), columns = isWater[0].size();
        
        queue <pair <int, int> > Q;
        
        vector < vector <int> > H(rows, vector <int> (columns, -1));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(isWater[i][j])
                {
                    Q.push(make_pair(i, j));
                    
                    H[i][j] = 0;
                }
            }
        }
        
        const int NO_OF_NEIGHBOURS = 4;
        int next_x[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1};
        int next_y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};
        
        while(!Q.empty())
        {
            pair <int, int> P = Q.front();
            Q.pop();
            
            for(int n = 0; n < NO_OF_NEIGHBOURS; n++)
            {
                int x = P.first + next_x[n];
                int y = P.second + next_y[n];
                
                if(is_inside(x, y, rows, columns) && H[x][y] == -1)
                {
                    H[x][y] = H[P.first][P.second] + 1;
                    
                    Q.push(make_pair(x, y));
                }
            }
        }
        
        return H;
    }
};
