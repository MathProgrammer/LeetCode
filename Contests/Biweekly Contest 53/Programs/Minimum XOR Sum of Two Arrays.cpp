class Solution {
public:
    
    int is_bit_set(int n, int bit)
    {
        return ( (n & (1 << bit)) != 0 );
    }
    
    int bit_count(int n)
    {
        int count = 0;
        while(n)
        {
            count += n%2;
            
            n /= 2;
        }
        
        return count;
    }
    
    int minimumXORSum(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        const int max_mask = (1 << n), oo = 1e9;
        
        vector < vector <int> > min_cost(max_mask, vector <int> (n, oo) );
        for(int i = 0; i < n; i++)
        {
            for(int m = 0; m < max_mask; m++)
            {
                if(bit_count(m) != i + 1)
                {
                    continue;
                }
                
                for(int last = 0; last < n; last++)
                {
                    if(!is_bit_set(m, last))
                    {
                        continue;
                    }
                    
                    int remaining_m = m^(1 << last);
                    
                    if(i == 0)
                    {
                        min_cost[m][i] = min(min_cost[m][i], A[i]^B[last]);
                        
                        continue;
                    }
                    
                    min_cost[m][i] = min(min_cost[m][i], min_cost[remaining_m][i - 1] + (A[i]^B[last]));
                }
            }
        }
        
        return min_cost[max_mask - 1][n - 1];
    }
};
