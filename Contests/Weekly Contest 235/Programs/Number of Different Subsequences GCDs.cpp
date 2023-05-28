class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) 
    {
        const int MAX_N = 2e5 + 5;
        vector <int> subsequence_gcd_for_multiples_of(MAX_N);
        for(int n : nums)
        {
            for(int i = 1; i*i <= n; i++)
            {
                if(n%i == 0)
                {
                    int factor_1 = i, factor_2 = n/i;

                    subsequence_gcd_for_multiples_of[factor_1] = __gcd(n, subsequence_gcd_for_multiples_of[factor_1]);

                    subsequence_gcd_for_multiples_of[factor_2] = __gcd(n, subsequence_gcd_for_multiples_of[factor_2]);
                }
            }
        }

        int subsequence_gcd = 0;
        for(int i = 1; i < MAX_N; i++)
        {
            if(subsequence_gcd_for_multiples_of[i] == i)
            {
                subsequence_gcd++;
            }
        }

        return subsequence_gcd;
    }
};
