class Solution 
{
    public:
    int rearrangeSticks(int n, int k) 
    {
        vector <vector <long long> > no_of_ways(n + 1, vector <long long> (k + 1));
        
        const int MOD = 1e9 + 7;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= min(k, i); j++)
            {
                if(i == 1)
                {
                    no_of_ways[i][j] = 1;
                    break;
                }
                
                long long smallest_first = no_of_ways[i - 1][j - 1];
                long long smallest_somewhere_else = ( (i - 1)*no_of_ways[i - 1][j] )%MOD;
                
                no_of_ways[i][j] = (smallest_first + smallest_somewhere_else)%MOD;
            }
        }
        
        return no_of_ways[n][k];
    }
};
