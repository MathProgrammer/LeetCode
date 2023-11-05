#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    const int ROOT = 0, PICKED_ABOVE = 0, PICKED_HERE = 1, PICKED_BELOW = 2;
    const long long oo = 1e14 + 9;

    void dfs(int v, int parent_v, vector <vector <long long>> &maximum_sum, vector <vector <int> > &tree, vector <int> &values)
    {
        if(tree[v].size() == 1 && v != ROOT)
        {
            maximum_sum[v][PICKED_ABOVE] = values[v];
            maximum_sum[v][PICKED_HERE] = 0;
            maximum_sum[v][PICKED_BELOW] = -oo;
            return;
        }

        maximum_sum[v][PICKED_ABOVE] = values[v];
        maximum_sum[v][PICKED_HERE] = 0;
        maximum_sum[v][PICKED_BELOW] = values[v];
        for(int child_v : tree[v])
        {
            if(child_v == parent_v)
            {
                continue;
            }

            dfs(child_v, v, maximum_sum, tree, values);

            maximum_sum[v][PICKED_ABOVE] += maximum_sum[child_v][PICKED_ABOVE];
            maximum_sum[v][PICKED_HERE] += maximum_sum[child_v][PICKED_ABOVE];
            maximum_sum[v][PICKED_BELOW] += max(maximum_sum[child_v][PICKED_HERE], maximum_sum[child_v][PICKED_BELOW]);
        }

    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values)
    {
        int no_of_vertices = values.size();
        vector <vector <int> > tree(no_of_vertices + 1);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector <vector <long long> > maximum_sum(no_of_vertices, vector <long long> (3, 0));
        dfs(0, -1, maximum_sum, tree, values);

        long long answer = max(maximum_sum[0][PICKED_HERE], maximum_sum[0][PICKED_BELOW]);
        return answer;
    }
};
