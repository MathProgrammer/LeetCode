class Solution {
public:
    
    int get_cost(int minutes, int seconds, int startAt, int moveCost, int pushCost)
    {
        string minute = to_string(minutes), second = to_string(seconds);
        
        string S ;
        
        if(minutes == 0)
        {
            S = second;
        }
        else 
        {
            if(second.size() == 1)
            {
                second = (char)('0') + second;
            }
            
            S = minute + second;
        }
        
        char current = (char)('0' + startAt);
        
        int cost = 0;
        
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] != current)
            {
                cost += moveCost;
            }
            
            cost += pushCost;
            current = S[i];
        }
        
        return cost;
    }
    
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) 
    {
        const int MAX_TIME = 100, oo = 1e9;
        int cost = oo;
        for(int minutes = 0; minutes < MAX_TIME; minutes++)
        {
            for(int seconds = 0; seconds < MAX_TIME; seconds++)
            {
                if(minutes*60 + seconds == targetSeconds)
                {
                    int cost_here = get_cost(minutes, seconds, startAt, moveCost, pushCost);
                    cost = min(cost, cost_here);
                }
            }
        }
        
        return cost;
    }
};
