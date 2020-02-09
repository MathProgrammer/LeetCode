using namespace std;

class Solution
{
    public:
    double angleClock(int hour, int minutes)
    {
        if(hour == 12)
        {
            hour = 0;
        }
        
        double hour_degree = hour*30 + (minutes*1.0/60.0)*30.0;
        double minute_degree = minutes*6;
        
        double angle = abs(hour_degree - minute_degree);
        
        return min(angle, 360.0 - angle);
    }
};
