#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

class Solution 
{
    public:
    
    void update(vector <int> &T, int n, int left, int right, int position, int value)
    {
        if(position < left || right < position)
        {
            return;
        }
        
        if(left == right)
        {
            T[n] = value;
            return;
        }
        
        int mid = (left + right)/2;
        update(T, LEFT(n), left, mid, position, value);
        update(T, RIGHT(n), mid + 1, right, position, value);
        
        T[n] = min(T[LEFT(n)], T[RIGHT(n)]);
    }
        
    int query(vector <int> &T, int n, int left, int right, int query_left, int query_right)
    {
        if(query_right < left || right < query_left || query_right < query_left || right < left)
        {
            const int oo = 1e9; 
            return oo;
        }
        
        if(query_left <= left && right <= query_right)
        {
            return T[n];
        }
        
        int mid = (left + right)/2;
        int left_answer = query(T, LEFT(n), left, mid, query_left, query_right);
        int right_answer = query(T, RIGHT(n), mid + 1, right, query_left, query_right);
        
        int answer = min(left_answer, right_answer); 
        return answer;
    }
    
    int minimumVisitedCells(vector<vector<int>>& grid) 
    {
        const int oo = 1e9;
        int rows = grid.size(), columns = grid[0].size();
        vector <vector <int>> row_min_tree(rows + 1, vector <int> (4*columns, oo));
        vector <vector <int>> column_min_tree(columns + 1, vector <int> (4*rows, oo));
        
        vector <vector <int> > answer(rows, vector <int> (columns, oo));
        
        for(int i = rows - 1; i >= 0; i--)
        {
            for(int j = columns - 1; j >= 0; j--)
            {
                if(i == rows - 1 && j == columns - 1)
                {
                    answer[i][j] = 1;
                }
                
                int column_left = j + 1, column_right = min(j + grid[i][j], columns - 1); 
                int row_left = i + 1, row_right = min(i + grid[i][j], rows - 1); 
                
                int row_answer = query(row_min_tree[i], 1, 0, columns - 1, column_left, column_right);
                int column_answer = query(column_min_tree[j], 1, 0, rows - 1, row_left, row_right);
                int best_path = 1 + min(row_answer, column_answer);
                
                answer[i][j] = min(answer[i][j], best_path);
                
               update(row_min_tree[i], 1, 0, columns - 1, j, answer[i][j]);
               update(column_min_tree[j], 1, 0, rows - 1, i, answer[i][j]); 
            }
        }

        int final_answer = (answer[0][0] >= oo ? -1 : answer[0][0]);
       
        return final_answer;
    }
};
