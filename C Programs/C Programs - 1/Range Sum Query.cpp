#include <bits/stdc++.h>
using namespace std;

class NumArray {

vector <int> sum_till;

public:
    NumArray(vector<int> nums) {

        for(unsigned int i = 0; i < nums.size(); i++)
            sum_till.push_back(i == 0 ? nums[i] : sum_till[i - 1] + nums[i]);
    }

    int sumRange(int i, int j) {
        return (i == 0 ? sum_till[j] : sum_till[j] - sum_till[i - 1]);
    }
};

