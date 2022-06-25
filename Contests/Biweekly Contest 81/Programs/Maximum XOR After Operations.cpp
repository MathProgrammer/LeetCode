class Solution {
public:
    
    int has_bit(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }
    
    int maximumXOR(vector<int>& nums) {
        const int MAX_BITS = 30;
        vector <int> is_set(MAX_BITS, false);
        
        for(int x : nums)
        {
            for(int bit = 0; bit < MAX_BITS; bit++)
            {
               if(has_bit(x, bit))
               {
                    is_set[bit] = true;
               }
            }
        }
                   
        int answer = 0;
        for(int bit = 0; bit < MAX_BITS; bit++)
        {
            if(is_set[bit])
            {
                answer |= (1 << bit);
            }
        }
        return answer;
    }
};
