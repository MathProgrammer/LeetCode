#include <string> 

using namespace std; 

class Solution 
{
    private: 
    long long power(long long x, long long p)
    {
        long long answer = 1; 
        while(p > 0)
        {
            answer *= x; 
            p--;
        }

        return answer;
    }
    
    long long countDistinctTill(string &N)
    {
        //cout << "N = " << N << "\n";
        long long count = 0; 
        for(int d = 1; d < N.size(); d++)
        {
            long long d_digit_numbers = power(9, d);
            count += d_digit_numbers;
        }
        
        for(int d = 0; d < N.size(); d++)
        {
            if(N[d] == '0')
            {
                break;
            }

            long long choices_for_current = N[d] - '1';
            long long suffix = power(9, N.size() - d - 1);
            long long count_with_this_prefix = choices_for_current*suffix;
            //cout << "choices = " << choices_for_current << "\n";

            count += count_with_this_prefix;
        }
        
        return count;
    }

    string convert_to_string(long long n)
    {
        string N;
        while(n > 0)
        {
            int digit = n%10;
            N += (char)('0' + digit);
            n /= 10;
        }

        reverse(N.begin(), N.end());
        return N;
    }
    
    public:
    long long countDistinct(long long n) 
    {
        string N = convert_to_string(n + 1);
        return countDistinctTill(N);
    }
};