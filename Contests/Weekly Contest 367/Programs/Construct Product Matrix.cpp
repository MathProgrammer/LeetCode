#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        const int MOD = 12345;
        int rows = grid.size(), columns = grid[0].size();
        vector <vector <long long> > row_prefix_product(rows, vector <long long> (columns, 1)), row_suffix_product(rows, vector <long long> (columns, 1));
        for(int r = 0; r < rows; r++)
        {
            for(int c = 1; c < columns; c++)
            {
                row_prefix_product[r][c] = grid[r][c - 1]*row_prefix_product[r][c - 1];
                row_prefix_product[r][c] %= MOD;
            }

            for(int c = columns - 2; c >= 0; c--)
            {
                row_suffix_product[r][c] = grid[r][c + 1]*row_suffix_product[r][c + 1];
                row_suffix_product[r][c] %= MOD;
            }
        }

        vector <long long> entire_product_prefix(rows, 1), entire_product_suffix(rows, 1);
        for(int r = 0; r < rows; r++)
        {
            int product = grid[r][columns - 1]*row_prefix_product[r][columns - 1];
            entire_product_prefix[r] = (r == 0 ? product : product*entire_product_prefix[r - 1]);
            entire_product_prefix[r] %= MOD;
        }

        for(int r = rows - 1; r >= 0; r--)
        {
            int product = grid[r][columns - 1]*row_prefix_product[r][columns - 1];
            entire_product_suffix[r] = (r == rows - 1 ? product : product*entire_product_suffix[r + 1]);
            entire_product_suffix[r] %= MOD;
        }

        vector <vector <int> > product(rows, vector <int> (columns));
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                long long before_rows = (r == 0 ? 1 : entire_product_prefix[r - 1]);
                long long after_rows = (r == rows - 1 ? 1 : entire_product_suffix[r + 1]);

                long long this_row_product = (row_prefix_product[r][c]*row_suffix_product[r][c])%MOD;
                long long other_rows_product = (before_rows*after_rows)%MOD;

                product[r][c] = (this_row_product*other_rows_product)%MOD;
            }
        }

        return product;
    }
};
