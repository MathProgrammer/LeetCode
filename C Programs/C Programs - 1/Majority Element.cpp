#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> frequency;

        for(unsigned int i = 0; i < nums.size(); i++)
            frequency[nums[i]]++;

        int max_frequency = 0, majority_element;
        for(map <int, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
        {
            int element_i = it->first, frequency_i = it-> second;
            if(frequency_i > max_frequency)
            {
                max_frequency = frequency_i;
                majority_element = element_i;
            }
        }

        return majority_element;
    }
};

