class Solution {
public:
    int countMonobit(int n) 
    {
        int count = 1; 
        int monobit = 1; 
        while(monobit <= n)
        {
            count++;
            monobit <<= 1; 
            monobit |= 1; 
        }

        return count;
    }
};