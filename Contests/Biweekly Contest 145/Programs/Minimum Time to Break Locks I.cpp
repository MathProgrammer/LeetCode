#include <vector> 

using namespace std; 

class Solution 
{
    public:
    int ceil(int numerator, int denominator)
    {
        return (numerator/denominator) + (numerator%denominator != 0);
    }

    int bit_count(int n)
    {
        int count = 0; 
        while(n > 0)
        {
            count += n%2;
            n /= 2;
        }

        return count;
    }

    int is_bit_set(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }

    int findMinimumTime(vector<int>& strength, int K) 
    {
        const int oo = 1e9;
        int max_mask = (1 << strength.size()); 
        vector <int> min_time(max_mask, oo); 
        min_time[0] = 0;
        
        for(int m = 0; m < max_mask; m++)
        {
            for(int bit = 0; bit < strength.size(); bit++)
            {
                if(!is_bit_set(m, bit))
                {
                    continue;
                }

                int time_without_this = min_time[m^(1 << bit)];
                int total_bits = bit_count(m) - 1;

                int increase = 1 + total_bits*K;
                int time_till_here = ceil(strength[bit], increase);

                min_time[m] = min(min_time[m], 
                        time_till_here + time_without_this);
            }
        }
        
        return min_time[max_mask - 1];
    }
};