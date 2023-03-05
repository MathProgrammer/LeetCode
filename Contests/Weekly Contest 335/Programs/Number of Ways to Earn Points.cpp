class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) 
    {
        const int MOD = 1e9 + 7;
        int no_of_questions = types.size();
        vector <int> multiplier(no_of_questions + 1);
        vector <long long> no_of_ways(target + 1);
        no_of_ways[0] = 1;
        
        for(int i = 0; i < no_of_questions; i++)
        {
            vector <long long> no_of_ways_here(target + 1);
            
            int current_count = types[i][0], current_weight = types[i][1];
            for(int multiplier = 0; multiplier*current_weight <= target && multiplier <= current_count; multiplier++)
            {
                int current_sum = multiplier*current_weight;
                for(int previous_sum = 0; previous_sum + multiplier*current_weight <= target; previous_sum++)
                {
                    int total_sum = previous_sum + current_sum;
                    no_of_ways_here[total_sum] += no_of_ways[previous_sum];
                    no_of_ways_here[total_sum] %= MOD;
                }
            }
            
            no_of_ways = no_of_ways_here;
        }
        
        return no_of_ways[target];
    }
};
