#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs_cycle(int v, vector <int> &E, vector <int> &visited)
    {
        if(visited[v])
        {
            return v;
        }

        visited[v] = true;

        return dfs_cycle(E[v], E, visited);
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        int no_of_vertices = edges.size();

        vector <int> visited(no_of_vertices, false);
        vector <int> on_cycle(no_of_vertices, false);
        vector <int> answer(no_of_vertices);
        for(int i = 0; i < no_of_vertices; i++)
        {
            if(answer[i] > 0)
            {
                continue;
            }

            int current_component_cycle_start = dfs_cycle(i, edges, visited);
            int v = current_component_cycle_start;
            int current_v = edges[v];
            int cycle_size = 1;
            while(current_v != v)
            {
                current_v = edges[current_v];
                cycle_size++;
            }

            queue <int> Q;
            Q.push(v);
            answer[v] = cycle_size;
            on_cycle[v] = true;
            current_v = edges[v];
            while(current_v != v)
            {
                answer[current_v] = cycle_size;
                on_cycle[current_v] = true;
                Q.push(current_v);

                current_v = edges[current_v];
            }

            vector <vector <int>> reverse_edges(no_of_vertices);
            for(int i = 0; i < edges.size(); i++)
            {
                int target = edges[i];

                if(!on_cycle[i])
                {
                    reverse_edges[target].push_back(i);
                }
            }

            while(!Q.empty())
            {
                int v = Q.front();
                Q.pop();

                for(int child_v : reverse_edges[v])
                {
                    answer[child_v] = answer[v] + 1;
                    Q.push(child_v);
                }
            }
        }


        return answer;
    }
};
