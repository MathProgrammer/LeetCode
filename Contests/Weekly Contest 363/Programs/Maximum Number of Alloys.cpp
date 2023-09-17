#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    long long calculate_cost(long long no_of_pieces, vector <int> &requirement_per_piece, vector <int> &stock, vector <int> &cost)
    {
        long long total_cost = 0;
        for(int metal = 0; metal < requirement_per_piece.size(); metal++)
        {
            long long metals_needed = no_of_pieces*requirement_per_piece[metal];
            long long metals_bought_here = max(0LL, metals_needed - stock[metal]);
            total_cost += metals_bought_here*cost[metal];
        }
        return total_cost;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {

        int answer = 0;
        for(int i = 0; i < k; i++)
        {
            long long left = 0, right = 1e9;
            while(right - left > 1)
            {
                long long mid = (left + right)/2;
                long long total_cost = calculate_cost(mid, composition[i], stock, cost);

                if(total_cost <= budget)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }

            int answer_here = left;
            answer = max(answer, answer_here);
        }

        return answer;
    }
};
