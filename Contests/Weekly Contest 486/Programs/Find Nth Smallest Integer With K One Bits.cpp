#include <algorithm> 
using namespace std;
class Solution 
{
    private: 
    int is_bit_set(long long n, int bit)
    {
        return ( (n&(1LL << bit)) != 0 );
    }

    long long combinations(int n, int r)
    {
        if(n < r)
        {
            return 0;
        }
        
        long long d1 = r, d2 = n - r; 
        if(d1 < d2)
        {
            swap(d1, d2); 
        }

        long long answer = 1;
        for(int i = n, j = 1; i > d1; i--, j++)
        {
            answer *= 1LL*i; 
            if(j <= d2)
            {
                answer /= j;
            }
        }

        return answer;
    }
    
    long long good_integers_till(long long n, int set_bits)
    {
        const int NO_OF_BITS = 60; 
        int prefix_bits = 0;
        long long good_integers = 0;
        for(int bit = NO_OF_BITS; bit >= 0 && prefix_bits <= set_bits; bit--)
        {
            if(is_bit_set(n, bit))
            {
                int suffix = bit;
                good_integers += combinations(suffix, set_bits - prefix_bits);
                prefix_bits++;
            }
        }

        return good_integers;
    }
    
    public:
    long long nthSmallest(long long n, int k) 
    {
        long long left = 1, right = (1LL << 59);
        while(right - left > 1)
        {
            long long mid = left + (right - left)/2; 
            if(good_integers_till(mid, k) >= n)
            {
                right = mid;
            }
            else 
            {
                left = mid;
            }
        }

        long long answer = left;
        return answer;
    }
};