#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define min(a, b) (a < b ? a : b)
    #define all(v) (v).begin(), (v).end()

    vector<vector<int> > minimumAbsDifference(vector<int>& arr)
    {
        sort(all(arr));

        const long long oo = 1e12;
        long long minimum_difference = oo;
        for(int i = 0; i + 1 < arr.size(); i++)
        {
            minimum_difference = min(minimum_difference, abs(arr[i] - arr[i + 1]));
        }

        vector <vector <int> > answer;
        for(int i = 0; i + 1 < arr.size(); i++)
        {
            if(abs(arr[i + 1] - arr[i]) == minimum_difference)
            {
                vector <int> this_pair;
                this_pair.push_back(arr[i]);
                this_pair.push_back(arr[i + 1]);

                answer.push_back(this_pair);
            }
        }

        return answer;
    }
};
