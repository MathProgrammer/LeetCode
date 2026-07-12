#include <vector> 

using namespace std; 

class Solution 
{
    private: 
    int is_lesser(vector <vector <int> > &grid, int c1, int c2, int limit)
    {
        for(int r = 0; r < grid.size(); r++)
        {
            if(abs(grid[r][c1] - grid[r][c2]) > limit)
            {
                return false;
            }
        }

        return true;
    }
    
    public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) 
    {
        int columns = grid[0].size();
        int answer = 0;
        vector <int> max_from(columns + 1);
        for(int c = columns - 1; c >= 0; c--)
        {
            max_from[c] = 1; 
            for(int next_c = c + 1; next_c < columns; next_c++)
            {
                if(is_lesser(grid, c, next_c, limit))
                {
                    max_from[c] = max(max_from[c], 1 + max_from[next_c]);
                }
            }
            
            answer = max(answer, max_from[c]);
        }

        return answer;
    }
};