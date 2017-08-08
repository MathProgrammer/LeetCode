#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isPerfectSquare(int num) {

        int root = (int) sqrt(num);

        return (root*root == num ? true : false);
    }
};
