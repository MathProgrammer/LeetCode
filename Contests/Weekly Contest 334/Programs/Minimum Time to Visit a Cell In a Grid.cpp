class Solution {
public:
    
    int cell_value(int r, int c, int R, int C)
    {
        return (r*C + c);
    }
    
    int inside_grid(int r, int c, int R, int C)
    {
        return (0 <= r && r < R && 0 <= c && c < C);
    }
    
    int minimumTime(vector<vector<int>>& grid) {
        
        const int NO_OF_NEIGHBOURS = 4;
        int next_r[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1};
        int next_c[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};
        
        const int oo = 1e9;
        int rows = grid.size(), columns = grid[0].size();
        vector <vector <long long>> time_to_reach(rows, vector <long long> (columns, oo));
        
        int current_r = 0, current_c = 0, finish_time = 0;
        time_to_reach[current_r][current_c] = finish_time;
        
        priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > PQ;
        PQ.push(make_pair(finish_time, cell_value(current_r, current_c, rows, columns)));
        
        while(!PQ.empty())
        { 
            current_r = PQ.top().second/columns; 
            current_c = PQ.top().second%columns; 
            PQ.pop();
            
            int good_neighbours = 1;
            
            if(current_r == 0 && current_c == 0)
            {
                good_neighbours = 0;
                
                for(int n = 0; n < NO_OF_NEIGHBOURS; n++)
                {
                    int neighbour_r = current_r + next_r[n];
                    int neighbour_c = current_c + next_c[n];
                    
                    if(inside_grid(neighbour_r, neighbour_c, rows, columns) && 
                      grid[neighbour_r][neighbour_c] <= time_to_reach[current_r][current_c] + 1)
                    {
                        good_neighbours++;
                    }
                
                }
            }
            
           
            for(int n = 0; n < NO_OF_NEIGHBOURS; n++)
            {
                int neighbour_r = current_r + next_r[n];
                int neighbour_c = current_c + next_c[n];
                
                if(!inside_grid(neighbour_r, neighbour_c, rows, columns))
                {
                    continue;
                }
                
                int waiting_moves = 0;
                
                if(good_neighbours > 0 && 
                   grid[neighbour_r][neighbour_c] > time_to_reach[current_r][current_c] + 1)
                {
                   waiting_moves = (grid[neighbour_r][neighbour_c] - 1) - time_to_reach[current_r][current_c];
                }
                
                if(good_neighbours > 0 && 
                   grid[neighbour_r][neighbour_c] > time_to_reach[current_r][current_c] + 1 && 
                   grid[neighbour_r][neighbour_c]%2 == time_to_reach[current_r][current_c]%2)
                {
                    waiting_moves++;
                }
                
                int new_time_to_reach = time_to_reach[current_r][current_c] + waiting_moves + 1;
                
                if(new_time_to_reach >= grid[neighbour_r][neighbour_c] && 
                   new_time_to_reach < time_to_reach[neighbour_r][neighbour_c])
                {
                    time_to_reach[neighbour_r][neighbour_c] = new_time_to_reach;
                    PQ.push(make_pair(new_time_to_reach, cell_value(neighbour_r, neighbour_c, rows, columns)));
                }
            }
        }
        
        int answer = (time_to_reach[rows - 1][columns - 1] != oo ? time_to_reach[rows - 1][columns - 1] : -1);
        return answer;
    }
};
