#include <map> 
#include <set> 

using namespace std; 

class RideSharingSystem 
{
    private: 
    set <int> riders, drivers;
    map <int, int> rider_time, driver_time, time_for_rider;
    int time;
    
    public:
    RideSharingSystem() 
    {
        time = 0;
    }
    
    void addRider(int riderId) 
    {
        time++;
        rider_time[time] = riderId;
        time_for_rider[riderId] = time;
        riders.insert(time);    
    }
    
    void addDriver(int driverId) 
    {
        time++;
        driver_time[time] = driverId;
        drivers.insert(time);    
    }
    
    vector<int> matchDriverWithRider() 
    {
        vector <int> match(2, -1); 
        if(riders.size() == 0 || drivers.size() == 0)
        {
            return match;
        }
        
        int earliest_rider = *riders.begin(); 
        int earliest_driver = *drivers.begin(); 
        
        match[0] = driver_time[earliest_driver], match[1] = rider_time[earliest_rider];

        drivers.erase(earliest_driver); 
        riders.erase(earliest_rider);

        return match;
    }
    
    void cancelRider(int riderId) 
    {
        int time_for_this_rider = time_for_rider[riderId];
        if(riders.count(time_for_this_rider) != 0)
        {
            riders.erase(time_for_this_rider);
        }
    }
};