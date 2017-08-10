#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {

        int sum_of_divisors = 0;
        for(int i = 1; i*i <= num; i++)
        {
            if(num%i == 0)
            {
                if(i*i != num)
                    sum_of_divisors += i + num/i;
                else
                    sum_of_divisors += i;
            }
        }

        return (sum_of_divisors == 2*num && num > 0 ? true : false);
    }
};
