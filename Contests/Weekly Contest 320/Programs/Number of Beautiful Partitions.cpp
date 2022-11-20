class Solution {
public:
    
    int is_prime(int d)
    {
        return (d == 2) || (d == 3) || (d == 5) || (d == 7);
    }
    
    int beautifulPartitions(string S, int k, int min_length) 
    {
        if(!is_prime(S[0] - '0'))
        {
            return 0;
        }
        
        const int MOD = 1e9 + 7;
        vector <vector <long long> > no_of_partitions(S.size() + 1, vector <long long> (k + 1, 0));
        vector <vector <long long> > sum(S.size() + 1, vector <long long> (k + 1));
        for(int p = 1; p <= k ; p++)
        {
            for(int i = min_length - 1; i < S.size(); i++)
            {
                if(!is_prime(S[i] - '0'))
                {
                    if(p == 1)
                    {
                        no_of_partitions[i][p] = 1;
                    }
                    else 
                    {
                        no_of_partitions[i][p] = (i == min_length - 1 ? 0 : sum[i - min_length][p - 1]);
                    }
                }
                
                sum[i][p] = (i == 0 ? 0 : sum[i - 1][p]);
                
                if(i + 1 == S.size() || is_prime(S[i + 1] - '0'))
                {
                    sum[i][p] += no_of_partitions[i][p];
                }
                
                sum[i][p] %= MOD;
            }
        }
        
        return no_of_partitions[S.size() - 1][k];
    }
};
