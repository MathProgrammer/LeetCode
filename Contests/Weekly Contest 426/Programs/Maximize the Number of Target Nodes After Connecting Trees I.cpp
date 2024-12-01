class Solution {
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
    
    int dfs(int v, int parent_v, int current_distance, int max_distance, vector <vector <int> > &tree)
    {
        if(current_distance > max_distance)
        {
            return 0;
        }
        
        int good_vertices_in_this_subtree = 1;
        
        for(int child_v : tree[v])
        {
            if(child_v == parent_v)
            {
                continue;
            }
            
            good_vertices_in_this_subtree += dfs(child_v, v, current_distance + 1, max_distance, tree);
        }
        
        return good_vertices_in_this_subtree;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) 
    {
        vector <vector <int> > tree1;
        build(tree1, edges1);
        
        vector <vector <int> > tree2;
        build(tree2, edges2);
        
        int no_of_vertices_1 = edges1.size() + 1;
        vector <int> good_vertices_from(no_of_vertices_1);
        for(int v = 0; v < no_of_vertices_1; v++)
        {
            good_vertices_from[v] = dfs(v, -1, 0, k, tree1);
        }
        
        int no_of_vertices_2 = edges2.size() + 1;
        int max_good_vertices_2 = 0;
        for(int v = 0; v < no_of_vertices_2; v++)
        {
            int good_vertices_from_v_in_2 = dfs(v, -1, 1, k, tree2);
            max_good_vertices_2 = max(max_good_vertices_2, good_vertices_from_v_in_2);
        }
        
        vector <int> answer(no_of_vertices_1);
        for(int v = 0; v < no_of_vertices_1; v++)
        {
            answer[v] = good_vertices_from[v] + max_good_vertices_2;
        }
        
        return answer;   
    }
};