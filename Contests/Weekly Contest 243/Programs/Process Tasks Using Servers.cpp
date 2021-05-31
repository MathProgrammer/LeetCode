class Solution {
public:
    
    int min(int a, int b)
    {
        return (a < b ? a : b);
    }
    
    struct server 
    {
        int weight, index, time; 
        
        server(int W, int I, int T)
        {
            weight = W;
            index = I;
            time = T;
        }
    };
    
    //Implement > operator because we want Minimum Priority queue
    struct sort_by_weight
    {
        bool operator()(server &S1, server &S2)
        {
            if(S1.weight == S2.weight)
            {
                return (S1.index > S2.index);
            }
            
            return (S1.weight > S2.weight);
        }
    };
    
    //Implement > operator because we want Minimum Priority queue
    struct sort_by_time
    {
        bool operator()(server &S1, server &S2)
        {
            return (S1.time > S2.time);
        }
    };
    
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) 
    {
        const int MAX_N = 1e6 + 5;
        priority_queue <server, vector <server>, sort_by_weight> free;
        priority_queue <server, vector <server>, sort_by_time> occupied;
        
        for(int i = 0; i < servers.size(); i++)
        {
            free.push(server(servers[i], i, 0));
        }
        
        vector <int> assigned(tasks.size()); 
        int current_task = 0;
        for(int t = 0; current_task < tasks.size() ; )
        {   
            while(occupied.size() > 0 && occupied.top().time <= t)
            {
                server S = occupied.top(); 
                occupied.pop();
                
                free.push(S);
            }
            
            while(free.size() > 0 && current_task <= min(t, tasks.size() - 1))
            {
                server S = free.top(); 
                free.pop();
                
                assigned[current_task] = S.index;
                S.time = t + tasks[current_task];
                occupied.push(S);
                
                current_task++;
            }
            
            if(free.size() == 0)
            {
                t = occupied.top().time; 
            }
            else 
            {
                t = t + 1;
            }
        }
        
        return assigned;
    }
};
