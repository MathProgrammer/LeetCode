#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int product_digits(int n)
    {
        int product = 1;

        while(n)
        {
            product *= (n%10);

            n /= 10;
        }

        return product;
    }

    int sum_digits(int n)
    {
        int sum = 0;

        while(n)
        {
            sum += (n%10);

            n /= 10;
        }

        return sum;
    }

    int subtractProductAndSum(int n)
    {
        return (product_digits(n) - sum_digits(n));
    }
};
