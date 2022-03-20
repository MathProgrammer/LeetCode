class Solution 
{
    public:
    
    int is_bit_set(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }
    
    int score(int mask, int no_of_bits)
    {
        int score = 0;
        for(int bit = 0; bit < no_of_bits; bit++)
        {
            if(is_bit_set(mask, bit))
            {
                score += bit;
            }
        }
        score++;
        
        return score;
    }
    
    int required(int mask, int no_of_bits, vector <int> &alice)
    {
        int required_arrows = 0;
        for(int bit = 0; bit < no_of_bits; bit++)
        {
            if(is_bit_set(mask, bit))
            {
                required_arrows += alice[bit] + 1;
            }
        }
        
        return required_arrows;
    }
    
    vector <int> construct(int mask, int no_of_bits, vector <int> &alice, int total)
    {
        vector <int> bob(no_of_bits);
        for(int bit = 0; bit < no_of_bits; bit++)
        {
            if(is_bit_set(mask, bit))
            {
                bob[bit] = alice[bit] + 1;
                total -= bob[bit];
            }
        }
        
        for(int bit = 0; bit < no_of_bits; bit++)
        {
            if(!is_bit_set(mask, bit) && total > 0)
            {
                bob[bit] = total;
                total -= bob[bit];
            }
        }
        
        return bob;
    }
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) 
    {
        const int NO_OF_TARGETS = 12;
        const int MAX_MASK = (1 << NO_OF_TARGETS);
        
        int bob_score = 0; 
        vector <int> bob_arrows(NO_OF_TARGETS);
        for(int m = 0; m < MAX_MASK; m++)
        {
            if(score(m, NO_OF_TARGETS) > bob_score && required(m, NO_OF_TARGETS, aliceArrows) <= numArrows)
            {
                bob_score = score(m, NO_OF_TARGETS);
                bob_arrows = construct(m, NO_OF_TARGETS, aliceArrows, numArrows);
            }
        }
        
        return bob_arrows;
    }
};
