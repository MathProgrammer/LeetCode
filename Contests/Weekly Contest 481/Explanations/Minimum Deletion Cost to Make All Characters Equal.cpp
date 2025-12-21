#include <vector> 

using namespace std;

class Solution {
public:
    long long minCost(string s, vector<int>& cost) 
    {
        const int NO_OF_ALPHABETS = 26;
        vector <long long> alphabet_cost(NO_OF_ALPHABETS); 
        long long total_cost = 0; 
        for(int i = 0; i < s.size(); i++)
        {
            total_cost += cost[i];
            alphabet_cost[s[i] - 'a'] += cost[i];
        }

        const long long oo = 1e18;
        long long best_cost = oo;
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            if(alphabet_cost[alpha] == 0)
            {
                continue;
            }

            long long cost_to_get_this_alphabet = total_cost - alphabet_cost[alpha];
            best_cost = min(best_cost, cost_to_get_this_alphabet);
        }

        return best_cost;
    }
};