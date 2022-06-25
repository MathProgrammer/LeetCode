class Solution {
public:
    int distinctSequences(int n) 
    {
        if(n == 1)
        {
            return 6;
        }
        
        const int MAX_N = 1e4 + 5, MAX_FACES = 6, MOD = 1e9 + 7;
        long long no_of_sequences[MAX_N][MAX_FACES + 1][MAX_FACES + 1];
        
        for(int i = 2; i <= n; i++)
        {
            for(int last = 1; last <= MAX_FACES; last++)
            {
                for(int second_last = 1; second_last <= MAX_FACES; second_last++)
                {
                    no_of_sequences[i][second_last][last] = 0;
                    if(__gcd(last, second_last) != 1 || last == second_last)
                    {
                        continue;
                    }
                    
                    if(i == 2)
                    {
                        no_of_sequences[i][second_last][last] = 1;
                        continue;
                    }
                    
                    for(int third_last = 1; third_last <= MAX_FACES; third_last ++)
                    {
                        if(__gcd(third_last, second_last) != 1 || third_last == last || third_last  == second_last)
                        {
                            continue;
                        }
                        
                        no_of_sequences[i][second_last][last] += no_of_sequences[i - 1][third_last][second_last];
                        no_of_sequences[i][second_last][last] %= MOD;
                    }
                }
            }
        }
        
        long long answer = 0;
        for(int second_last = 1; second_last <= MAX_FACES; second_last++)
        {
            for(int last = 1; last <= MAX_FACES; last++)
            {
                answer += no_of_sequences[n][second_last][last];
                answer %= MOD;
            }
        }
        
        return answer;
    }
};
