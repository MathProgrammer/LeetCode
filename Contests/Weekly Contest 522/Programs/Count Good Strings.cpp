#include <vector> 

using namespace std; 

class Solution 
{
    private: 
    vector <vector <int> > multiply(
                  vector <vector <int> > &A, 
                  vector <vector <int> > &B, 
                  int mod)
    {
        vector <vector <int> > product(A.size(), vector <int> (B[0].size()));
        for(int r = 0; r < A.size(); r++)
        {
            for(int c = 0; c < B[0].size(); c++)
            {
                for(int i = 0; i < A[r].size(); i++)
                {
                    product[r][c] += (A[r][i]*1LL*B[i][c])%mod; 
                    product[r][c] %= mod;
                }
            }
        }

        return product;
    }
    
    vector <vector <int> > power(
               vector <vector <int> > &multiplier, 
               long long power,
               int mod)
    {
        vector <vector <int> > answer{{1, 0}, 
                                      {0, 1}};
        while(power > 0)
        {
            if(power%2 == 1)
            {
                answer = multiply(answer, multiplier, mod);
            }

            power = power/2; 
            multiplier = multiply(multiplier, multiplier, mod);
        }

        return answer;
    }
    
    long long get_fibo(long long n, int mod)
    {
        vector <vector <int> > multiplier{{1, 1}, 
                                          {1, 0}}; 
        vector <vector <int> > final_multiplier = power(multiplier, n - 1, mod); 

        vector <vector <int> > base{{1}, {0}}; 
        vector <vector <int> >  product = multiply(final_multiplier, base, mod);

        return product[0][0];
    }

    public:
    int countGoodStrings(long long n) 
    {
        const int MOD = 1e9 + 7;
        long long fibo = get_fibo(n, MOD); 
        long long answer = (2*fibo)%MOD;
        return answer;
    }
};