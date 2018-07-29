#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    bool stoneGame(vector<int>& piles)
    {
        int no_of_piles = piles.size();

        typedef vector <int> v_int;

        v_int total(no_of_piles, 0);
        for(int i = 0; i < no_of_piles; i++)
            total[i] = (i == 0 ? piles[i] : total[i - 1] + piles[i]);

        vector <v_int> winner_stones(no_of_piles, v_int(no_of_piles));

        for(int length = 1; length <= no_of_piles; length++)
        {
            for(int left = 0, right = left + length - 1; right < no_of_piles; left++, right++)
            {
                if(length == 1)
                {
                    winner_stones[left][right] = piles[left];
                }
                else
                {
                    int second_move_after_taking_left = (total[right] - total[left]) - winner_stones[left + 1][right];
                    int taking_left = piles[left] + second_move_after_taking_left;

                    int second_move_after_taking_right = (total[right - 1] - total[left - 1]) - winner_stones[left][right - 1];
                    int taking_right = piles[right] + second_move_after_taking_right;

                    winner_stones[left][right] = max(taking_left, taking_right);
                }
            }
        }

        //Check if you can take more than half the stones.
        return (2*winner_stones[0][no_of_piles - 1] > total[no_of_piles - 1] ? true : false);
    }
};
