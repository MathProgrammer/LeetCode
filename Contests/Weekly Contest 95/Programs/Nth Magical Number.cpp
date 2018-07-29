#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    int gcd(int x, int y)
    {
        if(min(x, y) == 0)
            return max(x, y);
        else
            return gcd(min(x, y), max(x, y)%min(x, y));
    }

    int nthMagicalNumber(int N, int A, int B)
    {
        long long lcm = (A*1LL*B)/gcd(A, B);

        int no_of_lcm_multiples = lcm/A + lcm/B - 1;

        const int MOD = 1e9 + 7;

        long long no_of_lcms = (lcm*(N/no_of_lcm_multiples))%MOD;

        long long answer = 0;

        for(int last_a = 1, last_b = 1, i = 1; i <= N%no_of_lcm_multiples; i++)
        {
            if(A*last_a < B*last_b)
            {
                answer = (A*last_a)%MOD;
                last_a++;
            }
            else
            {
                answer = (B*last_b)%MOD;
                last_b++;
            }
        }

        answer = (answer + no_of_lcms)%MOD;

        return answer;
    }
};
