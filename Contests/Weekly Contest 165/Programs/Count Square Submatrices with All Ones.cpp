#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    int min_3(int a, int b, int c)
    {
        return min(a, min(b, c));
    }

    int countSquares(vector< vector<int> >& matrix)
    {
        int rows = matrix.size(), columns = matrix[0].size();

        int squares = 0;

        vector <vector <int> > max_order_at(rows + 1, vector <int> (columns + 1, 0));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(matrix[i][j] == 0)
                {
                    continue;
                }

                max_order_at[i][j] = 1;

                if(i > 0 && j > 0)
                {
                    max_order_at[i][j] = min_3(max_order_at[i - 1][j], max_order_at[i - 1][j - 1], max_order_at[i][j - 1]) + 1;
                }

                squares += max_order_at[i][j];
            }
        }

        return squares;
    }
};
