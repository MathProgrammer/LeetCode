#include <bits/stdc++.h>
using namespace std;

#define GOING_UP 0
#define GOING_DOWN 1
#define max_3(a, b, c) max(a, max(b, c))

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        int no_of_elements = nums.size();

        typedef vector <int> v_int;
        vector <v_int> maximum_wiggle_sequence_ending_here(2, v_int(no_of_elements, 1));

        int maximum_wiggle_sequence_length = 0;
        for(int i = 0; i < no_of_elements; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    maximum_wiggle_sequence_ending_here[GOING_UP][i] = max(maximum_wiggle_sequence_ending_here[GOING_UP][i],
                                                                          1 + maximum_wiggle_sequence_ending_here[GOING_DOWN][j]);
                }
                else if(nums[j] > nums[i])
                {
                    maximum_wiggle_sequence_ending_here[GOING_DOWN][i] = max(maximum_wiggle_sequence_ending_here[GOING_DOWN][i],
                                                                            1 + maximum_wiggle_sequence_ending_here[GOING_UP][j]);
                }
            }

            maximum_wiggle_sequence_length = max_3(maximum_wiggle_sequence_length, maximum_wiggle_sequence_ending_here[GOING_UP][i],
                                                  maximum_wiggle_sequence_ending_here[GOING_DOWN][i]);
        }

        return maximum_wiggle_sequence_length;
    }
};
