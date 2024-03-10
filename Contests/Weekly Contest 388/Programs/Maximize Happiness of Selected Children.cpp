#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());

        long long total_happiness = 0;
        for(int i = 0; i < k; i++)
        {
            int total_decrement = i;
            int current_happiness = max(0, happiness[i] - total_decrement);
            total_happiness += current_happiness;
        }

        return total_happiness;
    }
};
