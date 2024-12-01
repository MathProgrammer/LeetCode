#include <bits/stdc++.h>

using namespace std; 

Solution {
public:
    
    void build(vector <vector <int> > &tree, vector <vector <int> > &edges)
    {
        int no_of_vertices = edges.size() + 1; 
        tree.resize(no_of_vertices); 
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            tree[u].push_back(v); 
            tree[v].push_back(u);
        }
    }
    
    void dfs(int v, int parent_v, int current_parity, vector <vector <int>>&tree, vector <int> &parity, vector <int> &parity_count)
    {
        parity[v] = current_parity; 
        parity_count[current_parity]++; 
        
        for(int child_v : tree[v])
        {
            if(child_v == parent_v)
            {
                continue;
            }
            
            int child_parity = (current_parity + 1)%2;
            dfs(child_v, v, child_parity, tree, parity, parity_count);
        }
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {
        vector <vector <int> > tree1;
        build(tree1, edges1);
        
        vector <vector <int> > tree2;
        build(tree2, edges2);
        
        int no_of_vertices_1 = edges1.size() + 1;
        vector <int> parity_count1(2); 
        vector <int> parity1(no_of_vertices_1);
        dfs(0, -1, 0, tree1, parity1, parity_count1);
        
        int no_of_vertices_2 = edges2.size() + 1;
        vector <int> parity_count2(2); 
        vector <int> parity2(no_of_vertices_2);
        dfs(0, -1, 0, tree2, parity2, parity_count2);
        
        int max_parity2 = max(parity_count2[0], parity_count2[1]);
        
        vector <int> answer(no_of_vertices_1);
        for(int v = 0; v < no_of_vertices_1; v++)
        {
            int parity_v = parity1[v]; 
            int vertices_with_same_parity = parity_count1[parity_v];
            answer[v] = vertices_with_same_parity + max_parity2;
        }
        
        return answer;
    }
};