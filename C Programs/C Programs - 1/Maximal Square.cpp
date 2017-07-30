#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int min_3(int a, int b, int c){
        return min(a, min(b, c));
    }

    int maximalSquare(vector< vector<char> >& matrix) {

        typedef vector <int> v_int;
        vector <v_int> maximum_square_ending_here(matrix.size());

        int maximum_square = 0;
        for(unsigned int row = 0; row < matrix.size() ; row++)
        {
            for(unsigned int column = 0; column < matrix[row].size(); column++)
            {
                if(row == 0 ||  column == 0 || matrix[row][column] == '0')
                    maximum_square_ending_here[row].push_back(matrix[row][column] - '0');
                else
                    if(matrix[row][column] == '1')
                        maximum_square_ending_here[row].push_back(1 + min_3(maximum_square_ending_here[row][column - 1],
                                                                     maximum_square_ending_here[row - 1][column - 1],
                                                                     maximum_square_ending_here[row - 1][column]) );

                maximum_square = max(maximum_square, maximum_square_ending_here[row][column]);
            }
        }

        int no_of_squares = maximum_square*maximum_square;
        return no_of_squares;
    }
};
