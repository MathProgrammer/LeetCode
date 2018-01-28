#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {

        int no_of_jewels = 0;

        for(int j = 0; j < J.size(); j++)
            for(int i = 0; i < S.size(); i++)
                no_of_jewels += (S[i] == J[j]);

        return no_of_jewels;
    }
};
