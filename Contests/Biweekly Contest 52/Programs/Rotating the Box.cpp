class Solution 
{
    public:
    
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int rows = box.size(), columns = box[0].size(); 
        
        vector <vector <char> > rotated(columns, vector <char> (rows));
        
        for(int i = 0, rotated_column = rows - 1; i < rows; i++, rotated_column--)
        {
            for(int j = 0; j < columns; j++)
            {
                rotated[j][rotated_column] = box[i][j];
            }
        }
        
        const char LEAF = '#', EMPTY = '.', OBSTACLE = '*';
        
        int new_rows = columns, new_columns = rows;
        for(int j = 0; j < new_columns; j++)
        {
            for(int left = 0, right = 0; left < new_rows; )
            {
                int obstacle = left; 
                
                while(obstacle < new_rows && rotated[obstacle][j] != OBSTACLE)
                {
                    obstacle++;
                }
                
                right = obstacle - 1; 
                
                while(left < right)
                {
                    while(left < right && rotated[left][j] == EMPTY)
                    {
                        left++;
                    }
                    
                    while(right > left && rotated[right][j] == LEAF)
                    {
                        right--;
                    }
                    
                    //L points to first non empty, R points to first non leaf
                    
                    if(left < right)
                    {   
                        swap(rotated[left][j], rotated[right][j]);

                        left++;
                        right--;
                    }
                }
                
                left = obstacle + 1;
                right = obstacle + 1;
                
            }
        }
        
        return rotated;
    }
};
