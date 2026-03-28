#include <vector> 
using namespace std; 

class Solution
{
    private: 
    vector <long long> factorial, inv_factorial;

    long long power_mod(long long x, long long power, int mod)
    {
        long long answer = 1; 
        while(power > 0)
        {
            if(power%2 == 1)
            {
                answer = (answer*x)%mod;
            }

            x = (x*x)%mod; 
            power = power/2;
        }

        return answer;
    }
    
    void precompute(int mod)
    {
        const int MAX_N = 1e5 + 5;
        factorial.resize(MAX_N);
        inv_factorial.resize(MAX_N);
        factorial[0] = 1; 
        for(int i = 1; i < MAX_N; i++)
        {
            factorial[i] = (i*1LL*factorial[i - 1])%mod;
        }

        inv_factorial[MAX_N - 1] = power_mod(factorial[MAX_N - 1], mod - 2, mod);
        for(int i = MAX_N - 2; i >= 0; i--)
        {
            inv_factorial[i] = ((i + 1)*1LL*inv_factorial[i + 1])%mod;
        }
    }

    int no_of_ways(int n, int r, int mod)
    {
        if(r == n || r == 0 || n == 0)
        {
            return 1;
        }
        
        int numerator = factorial[n];
        int inv_denominator = (inv_factorial[r]*1LL*inv_factorial[n - r])%mod;

        int answer = (numerator*1LL*inv_denominator)%mod;
        return answer;
    }
    
    public:
    int countVisiblePeople(int n, int pos, int k) 
    {
        const int MOD = 1e9 + 7;
        precompute( MOD);

        pos++;
        int answer = 0;    
        for(int i = 0; i <= k; i++)
        {
            if(i > pos - 1 || n - pos < k - i)
            {
                continue;
            }
            
            int prefix = no_of_ways(pos - 1, i, MOD); 
            int suffix = no_of_ways(n - pos, k - i, MOD); 

            answer += (prefix*2LL*suffix)%MOD;
            answer %= MOD;
        }
        return answer;
    }
};