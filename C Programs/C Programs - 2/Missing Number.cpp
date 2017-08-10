#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        for(unsigned int i = 0; i < nums.size(); i++)
            sum += nums[i];

        return (n*(n + 1))/2 - sum;
    }
};
