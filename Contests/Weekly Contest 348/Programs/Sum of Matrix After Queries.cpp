class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) 
    {
        set <int> rows_seen, columns_seen;
        int finalised_rows = 0, finalised_columns = 0;
        long long sum = 0; 
        for(int i = queries.size() - 1; i >= 0; i--)
        {
            const int ROW = 0, COLUMN = 1;
            int type = queries[i][0], index = queries[i][1], value = queries[i][2];
            switch(type)
            {
                case ROW :  if(rows_seen.count(index) == 1)
                            {
                                break;
                            }
                            sum += (n - finalised_columns)*value;
                            rows_seen.insert(index);
                            finalised_rows++;
                            break;
                    
                case COLUMN : if(columns_seen.count(index) == 1)
                              {
                                 break;
                              }
                              columns_seen.insert(index);
                              sum += (n - finalised_rows)*value;
                              columns_seen.insert(index);
                              finalised_columns++;
                              break;
            }
        }
        
        return sum;
    }
};
