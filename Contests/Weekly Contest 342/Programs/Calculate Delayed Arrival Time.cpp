class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        const int NO_OF_HOURS = 24;
        return (arrivalTime + delayedTime)%NO_OF_HOURS;
    }
};
