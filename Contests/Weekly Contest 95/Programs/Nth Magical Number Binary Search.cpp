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

    int no_of_multiples(long long N, int A, int B)
    {
        long long lcm = (A*1LL*B)/gcd(A, B);

        return (N/A + N/B - N/lcm);
    }

    int nthMagicalNumber(int N, int A, int B)
    {
        long long left = 1, right = N*1LL*min(A, B);

        const int MOD = 1e9 + 7;

        while(left <= right)
        {
            long long mid = (left + right) >> 1;

            if(no_of_multiples(mid, A, B) >= N)
            {
                if(mid == left || no_of_multiples(mid - 1, A, B) < N)
                {
                    long long answer = mid%MOD;

                    return answer;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                left = mid + 1;
            }
        }
    }
};
