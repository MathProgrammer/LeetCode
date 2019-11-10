#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int oddCells(int n, int m, vector< vector<int> >& indices)
    {
        vector <int> row_operations(n, 0);
        vector <int> column_operations(m, 0);

        for(int i = 0; i < indices.size(); i++)
        {
            row_operations[indices[i][0]]++;
            column_operations[indices[i][1]]++;
        }

        int odd_cells = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                odd_cells += ( (row_operations[i] + column_operations[j])%2 == 1);
            }
        }

        return odd_cells;
    }
};
