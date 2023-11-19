#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    int is_bit_set(long long n, int bit)
    {
        return ( (n&(1LL << bit)) != 0 );
    }

    int maximumXorProduct(long long a, long long b, int n)
    {
        for(int bit = n - 1; bit >= 0; bit--)
        {
            if(!is_bit_set(a, bit) && !is_bit_set(b, bit))
            {
                a |= (1LL << bit);
                b |= (1LL << bit);
            }
            else if(is_bit_set(a, bit) && !is_bit_set(b, bit) && a > b)
            {
                a ^= (1LL << bit);
                b ^= (1LL << bit);
            }
            else if(!is_bit_set(a, bit) && is_bit_set(b, bit) && b > a)
            {
                a ^= (1LL << bit);
                b ^= (1LL << bit);
            }
        }

        const int MOD = 1e9 + 7;
        a %= MOD, b %= MOD;

        int answer = (a*b)%MOD;
        return answer;
    }
};
