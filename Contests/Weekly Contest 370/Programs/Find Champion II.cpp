#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges)
    {
        vector <int> in_degree(n);
        for(int i = 0; i < edges.size(); i++)
        {
            in_degree[edges[i][1]]++;
        }

        set <int> champions;
        for(int i = 0; i < n; i++)
        {
            if(in_degree[i] == 0)
            {
                champions.insert(i);
            }
        }

        int winner = (champions.size() == 1 ? (*champions.begin()) : -1);

        return winner;
    }
};
