#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        vector <int> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        vector <int> prime;
        for(int i = 2; i < n; i++)
        {
            if(is_prime[i])
            {
                for(long long multiple = i*1LL*i; multiple <= n; multiple += i)
                {
                    is_prime[multiple] = false;
                }
                prime.push_back(i);
            }
        }

        return prime.size();
    }
};
