#include <vector> 
using namespace std; 

class Solution {
    private: 
        int is_bit_set(int n, int bit)
        {
            return ( (n&(1 << bit)) != 0 );
        }
        
        void dfs(int v, int parent_v, vector <int> &height, vector <vector <int> > &tree, vector <vector <int> > &parent)
        {
            parent[v][0] = parent_v; 
            height[v] = height[parent_v] + 1;
    
            for(int child_v : tree[v])
            {
                if(child_v == parent_v)
                {
                    continue;
                }
    
                dfs(child_v, v, height, tree, parent);
            }
        }
    
        void compute_table(vector <vector <int> > &parent, int L)
        {
            for(int l = 1; l < L; l++)
            {
                for(int v = 1; v < parent.size(); v++)
                {
                    int ancestor = parent[v][l - 1]; 
                    parent[v][l] = parent[ancestor][l - 1];
                }
            }
        }
    
        int lca(int u, int v, vector <vector <int> > &parent, vector <int> &height)
        {
            if(height[u] > height[v])
            {
                swap(u, v);
            }
    
            int L = parent[0].size();
            int distance = height[v] - height[u];
            for(int l = 0; l < L; l++)
            {
                if(is_bit_set(distance, l))
                {
                    v = parent[v][l];
                }
            }
    
            if(u == v)
            {
                return v;
            }
    
            for(int l = L - 1; l >= 0; l--)
            {
                if(parent[u][l] != parent[v][l])
                {
                    u = parent[u][l]; 
                    v = parent[v][l];
                }
            }
    
            return parent[v][0];
        }
    
        int get_distance(int u, int v, vector <int> &height, vector <vector <int> > &parent)
        {
            int l = lca(u, v, parent, height);
            return height[u] + height[v] - 2*height[l]; 
        }
    
        long long power_mod(long long x, long long power, int mod)
        {
            long long answer = 1; 
            while(power > 0)
            {
                if(power%2 == 1)
                {
                    answer = (answer*x)%mod;
                }
    
                x = (x*x)%mod; 
                power = power/2;
            }
    
            return answer;
        }
        
    public:
        vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) 
        {
            int no_of_vertices = edges.size() + 1;
            vector <vector <int> > tree(no_of_vertices + 1); 
            for(int i = 0; i < edges.size(); i++)
            {
                int u = edges[i][0], v = edges[i][1]; 
                tree[u].push_back(v); 
                tree[v].push_back(u);
            }
    
            const int MAX_L = 20;
            vector <int> height(no_of_vertices + 1);
            vector <vector <int> > parent(no_of_vertices + 1, vector <int> (MAX_L));
            dfs(1, 0, height, tree, parent);
    
            compute_table(parent, MAX_L);
    
            const int MOD = 1e9 + 7;
            vector <int> answer(queries.size()); 
            for(int i = 0; i < queries.size(); i++)
            {
                int u = queries[i][0], v = queries[i][1];
                int distance = get_distance(u, v, height, parent);
                answer[i] = (u == v ? 0 : power_mod(2, distance - 1, MOD) );
            }
            
            return answer; 
        }
    };