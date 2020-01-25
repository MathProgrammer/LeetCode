#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define all(v) (v).begin(), (v).end()

class Solution
{
    public:
    
    vector< vector<int> > diagonalSort(vector<vector<int> >& mat)
    {
        int rows = mat.size(), columns = mat[0].size();
        
        int no_of_diagonals = rows + columns;
        
        vector <vector <int> > diagonals(no_of_diagonals);
        
        const int OFFSET = columns;
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                int diagonal_no = OFFSET + (i - j); //cout << "D = " << diagonal_no << "\n";
                
                diagonals[diagonal_no].push_back(mat[i][j]);
            }
        }
        
        for(int i = 0; i < no_of_diagonals; i++)
        {
            sort(all(diagonals[i]));
        }
        
        vector <int> p(no_of_diagonals, 0);
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                int diagonal_no = OFFSET + (i - j);
                
                mat[i][j] = diagonals[diagonal_no][p[diagonal_no]];
                
                p[diagonal_no]++;
            }
        }
        
        return mat;
    }
};
