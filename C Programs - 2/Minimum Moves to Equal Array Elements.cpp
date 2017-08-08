#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {

        const int oo = INT_MAX;
        int minimum = oo;

        for(unsigned int i = 0; i < nums.size(); i++)
            minimum = min(minimum, nums[i]);

        int no_of_operations = 0;
        for(unsigned int i = 0; i < nums.size(); i++)
            no_of_operations += (nums[i] - minimum);

        return no_of_operations;
    }
};
