class Solution {
public:
    int passThePillow(int n, int time) {
        int round_trip_time = 2*(n - 1);
        time %= round_trip_time;
        
        int answer = 0;
        if(time > n - 1)
        {
            int back_steps = time - (n - 1);
            answer = n - back_steps;
        }
        else 
        {
            answer = time + 1;
        }
        
        return answer;
    }
};
