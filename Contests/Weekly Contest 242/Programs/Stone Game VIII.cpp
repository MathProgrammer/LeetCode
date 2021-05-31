class Solution {
public:
    int stoneGameVIII(vector<int>& stones) 
    {
        vector <int> sum_till(stones.size() + 1);
        sum_till[0] = stones[0];
        for(int i = 1; i < stones.size(); i++)
        {
            sum_till[i] = sum_till[i - 1] + stones[i];
        }
        
        vector <int> winner_difference(stones.size() + 1);
        winner_difference[stones.size() - 1] = sum_till[stones.size() - 1];
        for(int i = stones.size() - 2; i >= 0; i--)
        {
            int best_second_move = winner_difference[i + 1];
            winner_difference[i] = max(sum_till[i] - winner_difference[i + 1], winner_difference[i + 1]);
        }
        
        return winner_difference[1];
    }
};
