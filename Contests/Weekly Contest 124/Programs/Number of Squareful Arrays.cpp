class Solution {
public:

    int is_set_bit(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }

    int is_square(int n)
    {
        //L^2 <= n < R^2
        long long left = 0, right = 1e5;
        while(right - left > 1)
        {
            long long mid = (right + left)/2;

            if(mid*mid <= n)
            {
                left = mid;
            }
            else 
            {
                right = mid;
            }
        }

        return (left*left == n);
    }

    int factorial(int n)
    {
        int answer = 1;
        for(int i = 1; i <= n; i++)
        {
            answer *= i;
        }

        return answer;
    }

    int numSquarefulPerms(vector<int>& nums) {
        int max_mask = (1 << nums.size());
        vector <vector <int> > good_permutations(max_mask, vector <int> (nums.size()));

        for(int m = 0; m < max_mask; m++)
        {
            for(int last_bit = 0; last_bit < nums.size(); last_bit++)
            {
                for(int second_last_bit = 0; second_last_bit < nums.size(); second_last_bit++)
                {
                    if(!is_set_bit(m, last_bit) 
                    || !is_set_bit(m, second_last_bit) 
                    || last_bit == second_last_bit 
                    || !is_square(nums[last_bit] + nums[second_last_bit]))
                    {
                        continue;
                    }
                    
                    int m_without_last = m^(1 << last_bit);

                    if( (1 << last_bit) + (1 << second_last_bit) == m )
                    {
                        good_permutations[m][last_bit] = 1;
                    }
                    else
                    {
                        good_permutations[m][last_bit] += good_permutations[m_without_last][second_last_bit];
                    }
                    //cout << "S = " << nums[last_bit] + nums[second_last_bit] << " F(" << m << "," << last_bit <<") = " << good_permutations[m][last_bit] << "\n";
                }
            }
        }

        int answer = 0;
        for(int ending = 0; ending < nums.size(); ending++)
        {
            answer += good_permutations[max_mask - 1][ending];
        }

        map <int, int> frequency; 
        for(int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++;
        }

        for(auto it = frequency.begin(); it != frequency.end(); it++)
        {
            answer /= factorial(it->second);
        }

        return answer;
    }
};
