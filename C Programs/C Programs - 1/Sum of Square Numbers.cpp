#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {

        int square_sum = false;

        set <int> square;
        for(int i = 0; i*1LL*i <= INT_MAX; i++)
            square.insert(i*i);

        for(int a = 0; a*1LL*a <= c; a++)
            if(square.count(c - a*a) == 1)
                square_sum = true;

        return square_sum;

    }
};
