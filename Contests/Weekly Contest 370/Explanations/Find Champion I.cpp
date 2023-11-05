#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid)
    {
        int no_of_players = grid.size();
        vector <int> has_stronger_player(no_of_players);
        for(int i = 0; i < no_of_players; i++)
        {
            for(int j = 0; j < no_of_players; j++)
            {
                if(grid[i][j])
                {
                    has_stronger_player[j] = true;
                }
            }
        }

        int winner = -1;
        for(int i = 0; i < no_of_players; i++)
        {
            if(!has_stronger_player[i])
            {
                winner = i;
                break;
            }
        }

        return winner;
    }
};
