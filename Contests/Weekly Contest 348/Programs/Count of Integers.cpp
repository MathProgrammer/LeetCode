class Solution {
public:
    
    void precompute(vector <vector <int> > &no_of_ways, int mod, int sum, int no_of_digits)
    {
        no_of_ways[0][0] = 1;
        
        for(int s = 0; s <= sum; s++)
        {
            for(int d = 1; d <= no_of_digits; d++)
            {
                for(int last_digit = 0; last_digit <= min(s, 9); last_digit++)
                {
                    no_of_ways[s][d] += no_of_ways[s - last_digit][d - 1];
                    no_of_ways[s][d] %= mod;
                }
            }
        }
    }
    
    string add_1(string &N)
    {
        string N_plus_1 = N; 
        
        for(int i = N.size() - 1; i >= 0; i--)
        {
            if(N[i] == '9')
            {
                N_plus_1[i] = '0';
            }
            else 
            {
                N_plus_1[i] = N[i] + 1; 
                return N_plus_1;
            }
        }
        
        N_plus_1 = "1" + N_plus_1;
        return N_plus_1;
    }
    
    int count_till(string &N, int sum, vector <vector <int> > &no_of_ways, int mod)
    {
        int answer = 0;
        int prefix_sum = 0;
        for(int i = 0; i < N.size(); i++)
        {
            for(int d = 0; d < N[i] - '0'; d++)
            {   
                int prefix_sum_now = prefix_sum + d; 
                int required_suffix_sum = sum - prefix_sum_now, suffix_length = N.size() - (i + 1);
                
                if(required_suffix_sum < 0)
                {
                    break;
                }
                
                answer += no_of_ways[required_suffix_sum][suffix_length];
                answer %= mod;
            }
            
            prefix_sum += N[i] - '0';
        }

        return answer;
    }
    
    int count(string L, string R, int min_sum, int max_sum) 
    {
        const int MOD = 1e9 + 7, MAX_SUM = 401, MAX_D = 25; 
        vector <vector <int> > no_of_ways(MAX_SUM, vector <int> (MAX_D + 1));
        precompute(no_of_ways, MOD, MAX_SUM - 1, MAX_D - 1);
        
        string R_plus_1 = add_1(R); //cout << "R plus 1 = " << R_plus_1 << "\n";
        int answer = 0;
        for(int digit_sum = min_sum; digit_sum <= max_sum; digit_sum++)
        {
            answer += count_till(R_plus_1, digit_sum, no_of_ways, MOD); 
            answer %= MOD; 
            
            answer -= count_till(L, digit_sum, no_of_ways, MOD);
            answer += MOD; 
            answer %= MOD;
        }
        
        return answer;
    }
};
