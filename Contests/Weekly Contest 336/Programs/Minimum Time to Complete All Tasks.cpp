class Solution {
public:
    
    static int sort_by_right(vector <int> &A, vector <int> &B)
    {
        if(A[1] == B[1])
        {
            return (A[0] < B[0]);
        }
        
        return (A[1] < B[1]);
    }
    
    int findMinimumTime(vector<vector<int>>& tasks) {
        
        const int TIME_RANGE = 2001;
        vector <int> segments_beginning(TIME_RANGE), segments_ending(TIME_RANGE);
        for(int i = 0; i < tasks.size(); i++)
        {
            segments_beginning[tasks[i][0]]++;
            segments_ending[tasks[i][1]]++;
        }
        
        vector <int> segments_intersecting(TIME_RANGE);
        for(int t = 1; t < TIME_RANGE; t++)
        {
            segments_intersecting[t] = segments_intersecting[t - 1] + segments_beginning[t] - segments_ending[t - 1];
        }
        
        sort(tasks.begin(), tasks.end(), sort_by_right);
        
        vector <int> is_on(TIME_RANGE, false);
        for(int i = 0; i < tasks.size(); i++)
        {   cout << "i = " << i << "[" << tasks[i][0] << "," << tasks[i][1] << "," << tasks[i][2] << "]\n";
            for(int t = tasks[i][0]; t <= tasks[i][1]; t++)
            {
                if(is_on[t])
                {
                    tasks[i][2]--;
                }
            }
            
            vector <pair <int, int> > segments_on_at;
            for(int t = tasks[i][0]; t <= tasks[i][1]; t++)
            {
                segments_on_at.push_back(make_pair(segments_intersecting[t], t));
            }
            
            sort(segments_on_at.begin(), segments_on_at.end());
            reverse(segments_on_at.begin(), segments_on_at.end());
            
            for(int t = 0; t < segments_on_at.size() && tasks[i][2] > 0; t++)
            {
                int time = segments_on_at[t].second;
                
                if(is_on[time])
                {
                    continue;
                }
                
                is_on[time] = true;
                tasks[i][2]--;
                
                //cout << "Task " << i << " On at time " << time << " S = " << segments_intersecting[time] << "\n";
            }
         
            for(int t = tasks[i][0]; t <= tasks[i][1]; t++)
            {
                segments_intersecting[t]--;
            }
        }
        
        int total_on = 0;
        for(int t = 1; t < TIME_RANGE; t++)
        {
            total_on += is_on[t];
        }
        
        return total_on;
    }
};
