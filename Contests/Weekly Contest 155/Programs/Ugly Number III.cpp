#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    typedef long long LL;

    LL lcm(LL a, LL b)
    {
        return (a*b)/__gcd(a, b);
    }

    int calculate(int n, LL a, LL b, LL c)
    {
        LL lcm_ab = lcm(a, b), lcm_bc = lcm(b, c), lcm_ca = lcm(c, a);
        LL lcm_abc = lcm(a, lcm_bc);

        int multiples = n/a + n/b + n/c
                       -n/lcm_ab - n/lcm_bc - n/lcm_ca
                        + n/lcm_abc;

        return multiples;
    }

    int nthUglyNumber(int n, LL a, LL b, LL c)
    {
        const LL oo = 1e18;
        LL left = 0, right = oo; //Left always has less multiples than n, Right always has >= multiples than n

        while(right - left > 1) //When right - left = 1, then right is the answer
        {
            LL mid = (left + right)/2;

            LL multiples_till_mid = calculate(mid, a, b, c);

            if(multiples_till_mid >= n)
            {
                right = mid;
            }
            else if(multiples_till_mid < n)
            {
                left = mid;
            }
        }

        return right;
    }
};
