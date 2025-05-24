#include <set> 
using namespace std; 

class Solution {
    private: 
        int is_prime(long long n)
        {
            if(n <= 1)
            {
                return false;
            }
            
            for(long long i = 2; i*i <= n; i++)
            {
                if(n%i == 0)
                {
                    return false;
                }
            }
    
            return true;
        }
    public:
        long long sumOfLargestPrimes(string s) 
        {
            set <long long> S;
            for(int left = 0; left < s.size(); left++)
            {
                long long n = 0; 
                for(int right = left; right < s.size(); right++)
                {
                    n = n*10 + (s[right] - '0');
                    if(is_prime(n))
                    {
                        S.insert(n);
                    }
                }
            }
    
            long long sum = 0; 
            int count = 0;
            for(auto it = S.rbegin(); it != S.rend() && count < 3; it++, count++)
            {
                sum += *it;
            }
    
            return sum;
        }
    };