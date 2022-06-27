class Solution {
public:
    int countHousePlacements(int n) 
    {
        const int MOD = 1e9 + 7;
        vector <long long> no_of_ways(n + 1); 
        no_of_ways[0] = 1, no_of_ways[1] = 2;
        for(int i = 2; i <= n; i++)
        {
            no_of_ways[i] = (no_of_ways[i - 1] + no_of_ways[i - 2])%MOD;
        }
        
        long long answer = (no_of_ways[n]*no_of_ways[n])%MOD;
        return answer; 
    }
};
