#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int sum_ap(int first_term, int difference, int number_of_terms)
    {
        //a + (a + d) + ... + (a + (n - 1)d) = n.a + (1 + 2 + ... + n - 1).d
        return number_of_terms*first_term + sum_all(number_of_terms - 1)*difference;
    }

    int sum_all(int n)
    {
        return n*(n + 1)/2;
    }

    int differenceOfSums(int n, int m) {

        int divisible = sum_ap(m, m, n/m);
        int not_divisible = sum_all(n) - divisible;

        return not_divisible - divisible;
    }
};
