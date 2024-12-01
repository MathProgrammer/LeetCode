class Solution {
public:
    
    int no_of_bits(int n)
    {
        int bits = 0; 
        while(n > 0)
        {
            n >>= 1;
            bits++;
        }
        
        return bits;
    }
    
    int all_1s(int bits)
    {
        return (1 << bits) - 1;
    }
    
    int smallestNumber(int n) 
    {
        int total_bits = no_of_bits(n);
        return all_1s(total_bits);
    }
};