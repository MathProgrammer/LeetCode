class Solution {
public:
    
    void dfs(int v, int parent_v, vector <vector <int> > &T, vector <vector <int> > &parent, vector <int> &D)
    {
        parent[v][0] = parent_v;
        D[v] = D[parent_v] + 1;
        
        for(int child_v : T[v])
        {
            if(child_v == parent_v)
            {
                continue;
            }
            
            dfs(child_v, v, T, parent, D);
        }
    }
    
    void compute(vector <vector <int> > &parent, int max_log)
    {
        for(int l = 1; l < max_log; l++)
        {
            for(int v = 1; v < parent.size(); v++)
            {
                int previous_parent = parent[v][l - 1];
                parent[v][l] = parent[previous_parent][l - 1];
            }
        }
    }
    
    int is_bit_set(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }
    
    int find_lca(int u, int v, vector <int> &D, vector <vector <int> > &parent)
    {
        if(D[u] > D[v])
        {
            swap(u, v);
        }
        
        int difference = D[v] - D[u];
        const int MAX_BITS = 6;
        for(int bit = MAX_BITS - 1; bit >= 0; bit--)
        {
            if(is_bit_set(difference, bit))
            {
                v = parent[v][bit];
            }
        } //cout << "After lifting u = " << u << " D = " << D[u] << " v = " << v << " D = " << D[v] << "\n";
        
        if(u == v)
        {
            return v;
        }
        
        for(int bit = MAX_BITS - 1; bit >= 0; bit--)
        {
            if(parent[u][bit] != parent[v][bit])
            {
                u = parent[u][bit];
                v = parent[v][bit];
            }
        }
        
        return parent[v][0];
    }
    
    void mark(int v, int target, vector <vector <int> > &parent, vector <int> &contribution)
    {
        contribution[v]++;
        
        if(v == target)
        {
            return;
        }
        
        mark(parent[v][0], target, parent, contribution);
    }
    
    void dfs_minimum(int v, int parent_v, vector <vector <int> > &T, vector <int> &price, vector <int> &contribution, vector <vector <int> > &answer)
    {
        const int HALVING_HERE = 0, NOT_HALVING_HERE = 1;
        int cost_in_not_halving_children = 0, best_cost_in_children = 0;
        
        for(int child_v : T[v])
        {
            if(child_v == parent_v)
            {
                continue;
            }
            
            dfs_minimum(child_v, v, T, price, contribution, answer);
            
            cost_in_not_halving_children += answer[child_v][NOT_HALVING_HERE];
            best_cost_in_children += min(answer[child_v][HALVING_HERE], answer[child_v][NOT_HALVING_HERE]);
        }
        
        
        answer[v][NOT_HALVING_HERE] = contribution[v]*price[v] + best_cost_in_children;
        answer[v][HALVING_HERE] = contribution[v]*(price[v]/2) + cost_in_not_halving_children;
        
        /*cout << "F(" << v << "," << "not halving here) = " << answer[v][NOT_HALVING_HERE] << "\n";
        cout << "F(" << v << "," << "halving here) = " << answer[v][HALVING_HERE] << "\n";*/
    }
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector <vector <int> > tree(n + 1);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        const int MAX_L = 6;
        vector <vector <int> > parent(n + 1, vector <int> (MAX_L, 0));
        vector <int> depth(n + 2);
        dfs(0, n, tree, parent, depth);
        
        compute(parent, MAX_L);
        
        vector <int> contribution(n + 1);
        for(int i = 0; i < trips.size(); i++)
        {
            int start = trips[i][0], end = trips[i][1];
            int lca = find_lca(start, end, depth, parent);
            //cout << "LCA (" << start << "," << end << ") = " << lca << "\n";
            mark(start, lca, parent, contribution);
            mark(end, lca, parent, contribution);
            contribution[lca]--;
        }
        
        vector <vector <int> > minimum_total(n + 1, vector <int> (2, 0));
        dfs_minimum(0, n, tree, price, contribution, minimum_total);
        
        const int HALVING_HERE = 0, NOT_HALVING_HERE = 1;
        int answer = min(minimum_total[0][NOT_HALVING_HERE], minimum_total[0][HALVING_HERE]);
        
        return answer;
    }
};
