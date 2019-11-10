#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    vector<vector<int> > reconstructMatrix(int upper, int lower, vector<int>& colsum)
    {
        int n = colsum.size();
        vector <vector <int> > matrix(2, vector <int> (n, 0));

        for(int i = 0; i < n; i++)
        {
            if(colsum[i] == 0)
            {
                matrix[0][i] = matrix[1][i] = 0;
            }
            else if(colsum[i] == 2)
            {
                matrix[0][i] = matrix[1][i] = 1;

                upper--;
                lower--;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(colsum[i] == 1)
            {
                if(lower <= 0)
                {
                    matrix[0][i] = 1;
                    upper--;
                }
                else
                {
                    matrix[1][i] = 1;
                    lower--;
                }
            }
        }

        int possible = (upper == 0 && lower == 0);

        vector <vector <int> > empty_matrix;

        return (possible ? matrix : empty_matrix);
    }
};
