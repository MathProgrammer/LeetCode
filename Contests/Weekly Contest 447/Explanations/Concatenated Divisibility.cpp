#include <vector> 

using namespace std; 

class Solution 
{
    private: 
    int get_digit_count(int n)
    {
        int digits = 0;
        while(n > 0)
        {
            digits++; 
            n /= 10;
        }

        return digits;
    }

    int is_bit_set(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }

    int power_mod(int x, int power, int mod)
    {
        int result = 1; 
        while(power > 0)
        {
            if(power%2 == 1)
            {
                result = (result*x)%mod;
            }

            x = (x*x)%mod; 
            power = power/2;
        }

        return result;
    }

    bool is_smaller(vector <int> &A, int i, int current_min_index)
    {
        return (current_min_index == A.size() || A[i] < A[current_min_index]);
    }

    public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) 
    {
        int max_mask = 1 << (nums.size());
        vector <vector <int> > is_possible(max_mask, vector <int> (k, false));
        vector <int> digit_sum(max_mask, 0);
        is_possible[0][0] = true;
        for(int m = 1; m < max_mask; m++)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(!is_bit_set(m, i))
                {
                    continue;
                }

                int m_without_this_bit = m^(1 << i);
                int digits = get_digit_count(nums[i]);
                digit_sum[m] = digits + digit_sum[m_without_this_bit];

                for(int remainder = 0; remainder < k; remainder++)
                {
                    if(!is_possible[m_without_this_bit][remainder])
                    {
                        continue;
                    }

                    int new_remainder = (remainder*power_mod(10, digits, k) + nums[i])%k;
                    is_possible[m][new_remainder] = true;
                    
                }
            }
        }

        vector <int> answer; 

        if(!is_possible[max_mask - 1][0])
        {
            return answer;
        }

        int mask = max_mask - 1, required_mod = 0;
        while(answer.size() < nums.size())
        {
            int best_candidate_index = nums.size(), best_suffix_mod = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(!is_bit_set(mask, i))
                {
                    continue;
                }

                int remaining_mask = mask^(1 << i);
                int prefix_mod = (nums[i]*power_mod(10, digit_sum[remaining_mask], k))%k;
                int suffix_mod = (required_mod - prefix_mod + k)%k;

                if(is_possible[remaining_mask][suffix_mod] &&
                   is_smaller(nums, i, best_candidate_index))
                {
                    best_candidate_index = i;
                    best_suffix_mod = suffix_mod;
                }
            }

            answer.push_back(nums[best_candidate_index]);
            mask ^= (1 << best_candidate_index);
            required_mod = best_suffix_mod;
        }

        return answer;
    }
};