class Solution {
public:
    
    int exponent(int n, int f)
    {
        int answer = 0;
        while(n%f == 0)
        {
            n /= f; 
            answer++;
        }
        
        return answer;
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) 
    {
        int no_of_rows = grid.size(), no_of_columns = grid[0].size(); 
        
        vector <vector <int> > right_sum_2(no_of_rows, vector <int> (no_of_columns, 0));
        vector <vector <int> > right_sum_5(no_of_rows, vector <int> (no_of_columns, 0));
        
        vector <vector <int> > left_sum_2(no_of_rows, vector <int> (no_of_columns, 0));
        vector <vector <int> > left_sum_5(no_of_rows, vector <int> (no_of_columns, 0));
        for(int i = 0; i < no_of_rows; i++)
        {
            for(int j = no_of_columns - 1; j >= 0; j--)
            {
                right_sum_2[i][j] += exponent(grid[i][j], 2);
                right_sum_5[i][j] += exponent(grid[i][j], 5);
                
                if(j < no_of_columns - 1)
                {
                    right_sum_2[i][j] += right_sum_2[i][j + 1];
                    right_sum_5[i][j] += right_sum_5[i][j + 1];
                }
            }
            
            for(int j = 0; j < no_of_columns; j++)
            {
                left_sum_2[i][j] += exponent(grid[i][j], 2);
                left_sum_5[i][j] += exponent(grid[i][j], 5);
                
                if(j > 0)
                {
                    left_sum_2[i][j] += left_sum_2[i][j - 1];
                    left_sum_5[i][j] += left_sum_5[i][j - 1];
                }
            }
        }
        
        vector <vector <int> > up_sum_2(no_of_rows, vector <int> (no_of_columns, 0));
        vector <vector <int> > up_sum_5(no_of_rows, vector <int> (no_of_columns, 0));
        
        vector <vector <int> > down_sum_2(no_of_rows, vector <int> (no_of_columns, 0));
        vector <vector <int> > down_sum_5(no_of_rows, vector <int> (no_of_columns, 0));
        
        for(int j = 0; j < no_of_columns; j++)
        {
            for(int i = 0; i < no_of_rows; i++)
            {
                up_sum_2[i][j] = exponent(grid[i][j], 2);
                up_sum_5[i][j] = exponent(grid[i][j], 5);
                
                if(i > 0)
                {
                    up_sum_2[i][j] += up_sum_2[i - 1][j];
                    up_sum_5[i][j] += up_sum_5[i - 1][j];
                }
            }
            
            for(int i = no_of_rows - 1; i >= 0; i--)
            {
                down_sum_2[i][j] = exponent(grid[i][j], 2);
                down_sum_5[i][j] = exponent(grid[i][j], 5);
                
                if(i < no_of_rows - 1)
                {
                    down_sum_2[i][j] += down_sum_2[i + 1][j];
                    down_sum_5[i][j] += down_sum_5[i + 1][j];
                }
            }
        }
        
        int answer = 0;
        for(int i = 0; i < no_of_rows; i++)
        {
            for(int j = 0; j < no_of_columns; j++)
            {
                int left_up_answer = min(up_sum_2[i][j] + left_sum_2[i][j] - exponent(grid[i][j], 2), 
                                         up_sum_5[i][j] + left_sum_5[i][j] - exponent(grid[i][j], 5));
                
                int right_up_answer = min(up_sum_2[i][j] + right_sum_2[i][j] - exponent(grid[i][j], 2), 
                                          up_sum_5[i][j] + right_sum_5[i][j] - exponent(grid[i][j], 5));
                
                int up_answer = max(left_up_answer, right_up_answer);
                
                int left_down_answer = min(down_sum_2[i][j] + left_sum_2[i][j] - exponent(grid[i][j], 2), 
                                           down_sum_5[i][j] + left_sum_5[i][j] - exponent(grid[i][j], 5));
                
                int right_down_answer = min(down_sum_2[i][j] + right_sum_2[i][j] - exponent(grid[i][j], 2), 
                                            down_sum_5[i][j] + right_sum_5[i][j] - exponent(grid[i][j], 5));
                
                int down_answer = max(left_down_answer, right_down_answer);
                
                int answer_here = max(up_answer, down_answer);
                
                answer = max(answer, answer_here);
            }
        }
        
        return answer;
    }
};
