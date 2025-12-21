#include <vector> 

using namespace std; 

class Solution 
{
    private: 
    int no_of_groups;
    
    long long dfs(
        int parent_v, 
        int v, 
        vector <vector <int>> &tree, 
        vector <int> &group,
        vector <int> &total,
        vector <vector <int>> &subtree_total)
    {
        long long total_interactions = 0;

        subtree_total[v][group[v]]++;
        for(int child_v : tree[v])
        {
            if(child_v == parent_v)
            {
                continue;
            }

            total_interactions += dfs(v, child_v, tree, group, total, subtree_total);

            for(int g = 1; g <= no_of_groups; g++)
            {
                subtree_total[v][g] += subtree_total[child_v][g];
            }

            for(int g = 1; g <= no_of_groups; g++)
            {
                long long inside_child = subtree_total[child_v][g];
                long long remaining = total[g] - inside_child;
                long long no_of_times_this_edge_counts = inside_child*remaining; 
                total_interactions += no_of_times_this_edge_counts;
            }
        }

        return total_interactions;
    }
    
    public:
    long long interactionCosts(int no_of_vertices, vector<vector<int>>& edges, vector<int>& group) 
    {
        vector <vector <int> > tree(no_of_vertices);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            tree[u].push_back(v); 
            tree[v].push_back(u);
        }

        no_of_groups = 20; 
        vector <vector <int> > subtree_total(no_of_vertices, vector <int> (no_of_groups + 1));
        vector <int> total(no_of_groups + 1);
        for(int v = 0; v < no_of_vertices; v++)
        {
            total[group[v]]++;
        }

        long long total_interaction = dfs(-1, 0, tree, group, total, subtree_total);
        return total_interaction;
    }
};