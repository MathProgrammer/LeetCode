#include <string> 
#include <vector> 

using namespace std; 

class Solution 
{
    public:
    vector<string> createGrid(int rows, int columns, int k) 
    {
        vector <string> empty;
        
        const char BLOCK = '#', FREE = '.';
        vector <string> grid(rows);

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                grid[r] += BLOCK;
            }
        }

        if(k == 1)
        {
            for(int c = 0; c < columns; c++)
            {
                grid[0][c] = FREE;
            }

            for(int r = 0; r < rows; r++)
            {
                grid[r][columns - 1] = FREE;
            }

            return grid;
        }

        if(k == 4 && rows == columns && rows == 3)
        {
            grid[rows - 1][columns - 1] = FREE; 
            grid[rows - 1][columns - 2] = FREE; 
            grid[rows - 2][columns - 1] = FREE; 
            grid[rows - 2][columns - 2] = FREE; 
            grid[rows - 3][columns - 2] = FREE; 
            grid[rows - 2][columns - 3] = FREE; 
            grid[rows - 3][columns - 3] = FREE; 

            for(int c = 0; c < columns - 3; c++)
            {
                grid[0][c] = FREE;
            }

            for(int r = 0; r < rows - 3; r++)
            {
                grid[r][columns - 3] = FREE;
            }
            
            return grid;
        }

        grid[0][0] = FREE; 
        
        if(rows >= 2 && columns >= k)
        {
            for(int i = 0; i < k; i++)
            {
                grid[rows - 1][columns - 1 - i] = FREE; 
                grid[rows - 2][columns - 1 - i] = FREE; 
            }

            for(int c = 0; c <= columns - 1 - k; c++)
            {
                grid[0][c] = FREE; 
            }

            for(int r = 0; r <= rows - 2; r++)
            {
                grid[r][columns - 1 - k + 1] = FREE;
            }

            return grid;
        }

        if(columns >= 2 && rows >= k)
        {
            for(int i = 0; i < k; i++)
            {
                grid[rows - 1 - i][columns - 1] = FREE; 
                grid[rows - 1 - i][columns - 2] = FREE; 
            }

            for(int r = 0; r < rows; r++)
            {
                grid[r][columns - 2] = FREE; 
            }

            return grid;
        }

        return empty;
    }
};