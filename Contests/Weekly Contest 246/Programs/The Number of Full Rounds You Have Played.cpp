class Solution 
{
    public:
    
    int get_integer(string S, int l, int r)
    {
        return (S[l] - '0')*10 + (S[r] - '0');
    }
    
    int numberOfRounds(string startTime, string finishTime) 
    {
        int start_hour = get_integer(startTime, 0, 1), start_minute = get_integer(startTime, 3, 4);
        int finish_hour = get_integer(finishTime, 0, 1), finish_minute = get_integer(finishTime, 3, 4);
        cout << "H = " << start_hour << " M = " << start_minute << "\n";
        
        int rounds = 0, hour = start_hour, minute = start_minute;
        while(hour != finish_hour || minute != finish_minute)
        {
            if(hour != finish_hour && hour != start_hour)
            {
                rounds += 4;
                
                hour = (hour + 1)%24;
                minute = 0;
                continue;
            }
            
            if(hour == finish_hour && minute == 0)
            {   
                rounds += finish_minute/15;
                minute = finish_minute;
                continue;
            }
            
            if(hour == start_hour)
            {   
                if(hour == finish_hour && start_minute < finish_minute)
                {  
                    for(int time = 0; time <= 60; time += 15)
                    {
                        if(time >= start_minute)
                        {
                            minute = time; 
                            break;
                        }
                    }
                    //cout << "M = " << minute << "\n";
                    rounds += (finish_minute - minute)/15;
                    
                    minute = finish_minute;
                }
                else 
                {
                    rounds += (60 - minute)/15;
                    hour  = (hour + 1)%24;
                    minute = 0;
                }
            }
        }
        
        return rounds;
    }
};
