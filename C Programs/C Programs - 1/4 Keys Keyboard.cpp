#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxA(int N) {

        vector <int> maximum_output_with_operations(N + 1, 0);

        for(int i = 0; i <= N; i++)
        {
            if(i <= 6)
                maximum_output_with_operations[i] = i;
            else
            {
                for(int last_select = 2; last_select <= i - 2; last_select++)
                {
                    int output_so_far = maximum_output_with_operations[last_select-1];
                    int no_of_copies = i - (last_select + 1);

                    maximum_output_with_operations[i] = max(maximum_output_with_operations[i], output_so_far*(no_of_copies + 1));
                }
            }
        }

        return maximum_output_with_operations[N];

    }
};
