#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int set_bits(int n)
    {
        int bits = 0;
        while(n > 0)
        {
            bits += n%2;
            n /= 2;
        }
        return bits;
    }

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {

        int answer = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(set_bits(i) == k)
            {
                answer += nums[i];
            }
        }
        return answer;
    }
};
