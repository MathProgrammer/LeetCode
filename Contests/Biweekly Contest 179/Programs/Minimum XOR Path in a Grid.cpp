#include <vector> 

using namespace std; 

class Solution 
{
    private: 
    void combine(vector <int> &S, vector <int> &next, int value)
    {
        for(int i = 0; i < next.size(); i++)
        {
            if(next[i])
            {
                S[i^value] = true;
            }
        }
    }
    
    public:
    int minCost(vector<vector<int>>& grid) 
    {
        int rows = grid.size(), columns = grid[0].size(); 
        const int MAX_XOR = 1024;
        vector <vector <int>> values(rows*columns, vector <int> (MAX_XOR, false));
        for(int r = rows - 1; r >= 0; r--)
        {
            for(int c = columns - 1; c >= 0; c--)
            {
                int current_cell_no = r*columns + c; 
                
                if(r == rows - 1 && c == columns - 1)
                {
                    values[current_cell_no][grid[r][c]] = true;
                }

                if(c < columns - 1)
                {
                    int next_cell_no = r*columns + c + 1; 
                    combine(values[current_cell_no], values[next_cell_no], grid[r][c]);
                }

                if(r < rows - 1)
                {
                    int next_cell_no = (r + 1)*columns + c; 
                    combine(values[current_cell_no], values[next_cell_no], grid[r][c]);
                }
            }
        }

        int answer = 0; 
        for(int i = 0; i < MAX_XOR; i++)
        {
            if(values[0][i])
            {
                answer = i; 
                break;
            }
        }
        
        return answer;
    }
};