class Solution {
public:
    
    int is_bit_set(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }
    
    int minBitFlips(int start, int goal) 
    {
        const int NO_OF_BITS = 31;
        int flips = 0;
        for(int bit = 0; bit < NO_OF_BITS; bit++)
        {
            if(is_bit_set(start, bit) != is_bit_set(goal, bit))
            {
                flips++;
            }
        }
        
        return flips;
    }
};
