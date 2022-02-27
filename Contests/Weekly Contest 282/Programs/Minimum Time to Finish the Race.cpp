class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int change_time, int num_laps) 
    {   
        const long long oo = 1e15;
        const int MAX_CONSECUTIVE_LAPS  = 20;
        vector <long long> best_cost(MAX_CONSECUTIVE_LAPS + 1, 1e15);
        for(int i = 0; i < tires.size(); i++)
        {
            long long current_cost = tires[i][0];
            long long total_cost = current_cost;
            for(int p = 1; current_cost < change_time + tires[i][0]; p++)
            {
                best_cost[p] = min(best_cost[p], total_cost);
                
                current_cost *= tires[i][1];
                total_cost += current_cost;
            }
        }
        
        vector <long long> best_time_till(num_laps + 1, oo);
        best_time_till[0] = 0;
        for(int i = 1; i <= num_laps; i++)
        {   
            for(int laps = 1; laps <= i && laps <= MAX_CONSECUTIVE_LAPS; laps++)
            {
                
                if(laps == i)
                {
                    best_time_till[i] = min(best_time_till[i], best_cost[laps]);
                }
                else 
                {
                    best_time_till[i] = min(best_time_till[i], change_time + best_cost[laps] + best_time_till[i - laps]);
                }
            }
        }
        
        return best_time_till[num_laps];
    }
};
