#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

class Solution
{
    public:

    int maximumSwap(int num)
    {
        vector <int> N;

        while(num > 0)
        {
            N.push_back(num%10);
            num /= 10;
        }

        reverse(all(N));

        vector <int> max_digit_position_from(N.size() + 1);
        for(int i = N.size() - 1; i >= 0; i--)
        {
            if(i == N.size() - 1)
            {
                max_digit_position_from[i] = i;
            }
            else
            {
                int current_max_position = max_digit_position_from[i + 1];

                if(N[i] > N[current_max_position])
                    current_max_position = i;

                max_digit_position_from[i] = current_max_position;
            }
        }

        for(int i = 0; i < N.size() - 1; i++)
        {
            int current_max_position = max_digit_position_from[i + 1];

            if(N[i] < N[current_max_position])
            {
                swap(N[i], N[current_max_position]);
                break;
            }
        }

        int answer = 0;
        for(int i = 0; i < N.size(); i++)
            answer = answer*10 + N[i];

        return answer;
    }
};
