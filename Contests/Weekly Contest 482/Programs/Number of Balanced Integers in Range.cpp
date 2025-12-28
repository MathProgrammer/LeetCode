#include <vector> 

using namespace std; 

class Solution 
{
    private: 
    void precompute(vector <vector <long long>> &no_of_ways)
    {
        const int MAX_SUM = 150, NO_OF_DIGITS = 16; 
        no_of_ways.resize(MAX_SUM); 
        for(int s = 0; s < no_of_ways.size(); s++)
        {
            no_of_ways[s].resize(NO_OF_DIGITS);
        }

        no_of_ways[0][0] = 1;
        for(int s = 0; s < MAX_SUM; s++)
        {
            for(int digits = 1; digits < NO_OF_DIGITS; digits++)
            {
                for(int current_digit = 0; current_digit <= min(9, s); current_digit++)
                {
                    no_of_ways[s][digits] += no_of_ways[s - current_digit][digits - 1];
                }
            }
        }
    }
    
    long long get_count(string &N, vector <vector <long long> > &no_of_ways)
    {
        long long answer = 0;
        vector <long long> sum(2); 
        for(int i = 0; i < N.size(); i++)
        {
            int current_digit = N[i] - '0';
            for(int d = 0; d < current_digit; d++)
            {
                int remaining_odd_digits = N.size()/2 - (i + 1)/2;
                int remaining_even_digits = N.size()/2 + N.size()%2 - (i/2 + 1);
                for(int target_sum = min(sum[0], sum[1]); target_sum <= 9*N.size(); target_sum++)
                {
                    int remaining_even_digits_sum = target_sum - sum[0] - (i%2 == 0 ? d : 0);
                    int remaining_odd_digits_sum = target_sum - sum[1] - (i%2 == 1 ? d : 0);

                    if(min(remaining_even_digits_sum, remaining_odd_digits_sum) < 0)
                    {
                        continue;
                    }

                    long long no_of_ways_for_even = no_of_ways[remaining_even_digits_sum][remaining_even_digits]; 
                    long long no_of_ways_for_odd = no_of_ways[remaining_odd_digits_sum][remaining_odd_digits];

                    answer += no_of_ways_for_even*no_of_ways_for_odd;
                }
            }

            sum[i%2] += current_digit;
        }

        return answer;
    }
    
    public:
    long long countBalanced(long long low, long long high) 
    {
        vector <vector <long long> > no_of_ways;
        precompute(no_of_ways);
        string R = to_string(high + 1), L = to_string(low); 
        return get_count(R, no_of_ways) - get_count(L, no_of_ways);
    }
};