#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int is_bit_set(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }

    int maxSum(vector<int>& nums, int k) {

        const int NO_OF_BITS = 30;
        vector <int> bit_frequency(NO_OF_BITS);
        for(int n : nums)
        {
            for(int bit = 0; bit < NO_OF_BITS; bit++)
            {
                bit_frequency[bit] += is_bit_set(n, bit);
            }
        }

        const int MOD = 1e9 + 7;
        long long square_sum = 0;
        for(int i = 1; i <= k; i++)
        {
            long long current_number = 0;
            for(int bit = NO_OF_BITS - 1; bit >= 0; bit--)
            {
                if(bit_frequency[bit] > 0)
                {
                    current_number |= (1 << bit);
                    bit_frequency[bit]--;
                }
            }

            current_number %= MOD;

            square_sum += (current_number*current_number)%MOD;
            square_sum %= MOD;
        }

        return square_sum;
    }
};
