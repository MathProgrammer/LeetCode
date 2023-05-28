class Solution {
public:
    
    struct cell 
    {
        int value, row, column, answer;
        
        cell(){}
        
        cell(int V, int R, int C)
        {
            value = V;
            row = R; 
            column = C;
        }
        
        int operator <(const cell &C)
        {
            if(value == C.value)
            {
                if(row == C.row)
                {
                    return (column < C.column);
                }
                
                return (row < C.row);
            }
            
            return (value > C.value);
        }
    };
    
    
    
    int maxIncreasingCells(vector<vector<int>>& mat) {
        vector <cell> A; 
        int rows = mat.size(), columns = mat[0].size();
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                A.push_back(cell(mat[r][c], r, c));
            }
        }
        
        sort(A.begin(), A.end());
        
        int overall_answer = 0;
        vector <int> row_max(rows), column_max(columns);
        for(int i = 0; i < A.size(); )
        {
            vector <cell> current_cells; 
            int j = i;
            for(j = i; j < A.size() && A[i].value == A[j].value; j++)
            {
                A[j].answer = 1 + max(row_max[A[j].row], column_max[A[j].column]);
                
                current_cells.push_back(A[j]);
            }
            i = j;
            
            for(cell c : current_cells)
            {
                row_max[c.row] = max(row_max[c.row], c.answer);
                column_max[c.column] = max(column_max[c.column], c.answer);
                overall_answer = max(overall_answer, c.answer);
            }
        }
        
        return overall_answer;
    }
};
