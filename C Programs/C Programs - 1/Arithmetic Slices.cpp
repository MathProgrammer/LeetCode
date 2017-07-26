#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

        int number_of_aps = 0, no_of_aps_till_here = 0;

        for(unsigned int i = 2; i < A.size(); i++)
        {
            no_of_aps_till_here = (A[i] - A[i - 1] == A[i - 1] - A[i - 2] ? no_of_aps_till_here + 1 : 0);
            number_of_aps += no_of_aps_till_here;
        }

        return number_of_aps;

    }
};
