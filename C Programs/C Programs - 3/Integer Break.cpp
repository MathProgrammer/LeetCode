#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    int power(int n, int power)
    {
        int result = 1;

        while(power)
        {
            if(power%2 == 1)
                result = result*n;

            n = n*n;
            power = power >> 1;
        }

        return result;
    }

    int integerBreak(int n)
    {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;

        int no_of_2s = 0, no_of_3s = 0;
        switch(n%3)
        {
            case 0 : no_of_3s = n/3; break;
            case 1 : no_of_2s = 2, no_of_3s = (n - 4)/3; break;
            case 2 : no_of_2s = 1, no_of_3s = (n - 2)/3; break;
        }

        int product = power(2, no_of_2s)*power(3, no_of_3s);

        return product;
    }
};
