#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    void sieve(int N, vector <int> &normal_form)
    {
        vector <int> largest_prime_factor(N, 0);
        normal_form[1] = 1;
        for(int i = 2; i < N; i++)
        {
            if(largest_prime_factor[i] == 0)
            {
                for(int multiple = i; multiple < N; multiple += i)
                {
                    largest_prime_factor[multiple] = i;
                }
            }

            int i_without_largest_prime = i, largest_prime_exponent = 0;
            while(i_without_largest_prime%largest_prime_factor[i] == 0)
            {
                i_without_largest_prime /= largest_prime_factor[i];
                largest_prime_exponent++;
            }

            normal_form[i] = (largest_prime_exponent%2 == 0 ? 1 : largest_prime_factor[i])*normal_form[i_without_largest_prime];
        }
    }

    long long maximumSum(vector<int>& nums) {

        const int MAX_N = 1e4 + 5;
        vector <int> normal_form(MAX_N);
        sieve(MAX_N, normal_form);

        long long answer = 0;
        vector <long long> sum_for_subset(MAX_N);
        for(int i = 0, index = 1; i < nums.size(); i++, index++)
        {
            int this_normal_form = normal_form[index];

            sum_for_subset[this_normal_form] += nums[i];

            answer = max(answer, sum_for_subset[this_normal_form]);
        }

        return answer;
    }
};
