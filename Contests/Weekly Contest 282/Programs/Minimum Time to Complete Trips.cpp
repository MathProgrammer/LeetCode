class Solution {
public:
    
    int completed_trips(vector <int> &time, long long T, int total_trips)
    {
        long long trips = 0;
        for(int i = 0; i < time.size(); i++)
        {
            trips += (T/time[i]);
            if(trips > total_trips)
            {
                return true;
            }
        }
        
        return (trips >= total_trips ? true : false);
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long left = 0, right = 1e18;
        while(right - left > 1)
        {
            long long mid = (left + right)/2;
            
            if(completed_trips(time, mid, totalTrips))
            {
                right = mid;
            }
            else 
            {
                left = mid;
            }
        }
        
        long long answer = right;
        return answer;
    }
};
