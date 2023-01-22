class Solution {
public:
    
    int is_power_of_2(int n)
    {
        return ( (n&(n - 1)) == 0 ) ;
    }
    
    bool isReachable(int targetX, int targetY) {
        
        return is_power_of_2(__gcd(targetX, targetY));
    }
};
