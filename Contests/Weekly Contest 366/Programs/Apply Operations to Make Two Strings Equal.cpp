#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int parity(string S)
    {
        int bits = 0;
        for(char ch : S)
        {
            bits += (ch == '1');
        }

        return bits%2;
    }

    int minOperations(string s1, string s2, int x) {
        if(parity(s1) != parity(s2))
        {
            return -1;
        }

        vector <int> unequal_indices;
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                unequal_indices.push_back(i);
            }
        }

        vector <int> min_cost(unequal_indices.size());
        for(int i = 0; i < unequal_indices.size(); i++)
        {
            if(i == 0)
            {
                min_cost[i] = x;
            }
            else
            {
                int segment_flip_cost = 2*(unequal_indices[i] - unequal_indices[i - 1]) +
                    (i >= 2 ? min_cost[i - 2] : 0);
                int distant_flip_cost = x + min_cost[i - 1];

                min_cost[i] = min(segment_flip_cost, distant_flip_cost);
            }

        }

        int answer = (unequal_indices.size() > 0 ? min_cost.back()/2 : 0);

        return answer;
    }
};
