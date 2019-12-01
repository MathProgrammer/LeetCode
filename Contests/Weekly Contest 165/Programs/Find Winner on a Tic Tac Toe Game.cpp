#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    string tictactoe(vector< vector<int> >& moves)
    {
        vector <vector <char> > grid(3, vector <char>(3, '.'));
        for(int i = 0; i < moves.size(); i++)
        {
            if(i%2 == 0)
            {
                grid[moves[i][0]][moves[i][1]] = 'X';
            }
            else
            {
                grid[moves[i][0]][moves[i][1]] = 'O';
            }
        }

        if(grid[1][1] != '.')
        {
            if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
            {
                return (grid[1][1] == 'X' ? "A" : "B");
            }

            if(grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2])
            {
                return (grid[1][1] == 'X' ? "A" : "B");
            }
        }

        for(int i = 0; i < 3; i++)
        {
            if(grid[i][0] != '.' && grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
            {
                return (grid[i][0] == 'X' ? "A" : "B");
            }

            if(grid[0][i] != '.' && grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
            {
                return (grid[0][i] == 'X' ? "A" : "B");
            }
        }

        if(moves.size() < 9)
        {
            return "Pending";
        }

        return "Draw";
    }
};
