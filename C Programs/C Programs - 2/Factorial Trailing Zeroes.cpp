#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {

        int no_of_zeroes = 0;
        while(n > 0)
        {
            no_of_zeroes += n/5;
            n = n/5;
        }

        return no_of_zeroes;
    }
};
