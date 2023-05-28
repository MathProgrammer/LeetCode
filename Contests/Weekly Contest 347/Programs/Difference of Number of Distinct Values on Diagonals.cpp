class Solution {
public:
    
    int abs(int n)
    {
        return (n < 0 ? -n : n);
    }
    
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        
        int rows = grid.size(), columns = grid[0].size(); 
        vector <vector <int> > answer(rows, vector <int> (columns));
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                set <int> top_left; 
                for(int i = 1;  r - i >= 0 && c - i >= 0; i++)
                {
                    top_left.insert(grid[r - i][c - i]);
                }
                
                set <int> bottom_right;
                for(int i = 1; r + i < rows && c + i < columns; i++)
                {
                    bottom_right.insert(grid[r + i][c + i]);
                }
                
                answer[r][c] = abs(top_left.size() - bottom_right.size());
            }
        }
        
        return answer;
    }
};
