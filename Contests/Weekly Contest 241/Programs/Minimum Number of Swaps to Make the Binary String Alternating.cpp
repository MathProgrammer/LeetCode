class Solution 
{
    public:
    int minSwaps(string S) 
    {
        vector < vector <int> > count(2, vector <int> (2, 0));
        for(int i = 0; i < S.size(); i++)
        {
            count[i%2][S[i] - '0']++;
        }
        
        int even_positions = S.size()/2 + S.size()%2, odd_positions = S.size()/2;
        
        const int EVEN = 0, ODD = 1;
        if(count[EVEN][0] + count[ODD][0] != even_positions && count[EVEN][0] + count[ODD][0] != odd_positions)
        {
            return -1;
        }
        
        int minimum_swaps = S.size();
        
        if(count[EVEN][0] + count[ODD][0] == even_positions)
        {
            minimum_swaps = count[ODD][0];
        }
        
        if(count[EVEN][1] + count[ODD][1] == even_positions)
        {
            minimum_swaps = min(minimum_swaps, count[ODD][1]);
        }
        
        return minimum_swaps;
    }
};
