class Solution {
public:
    long long choose_2(long long n)
    {
        return (n*(n - 1))/2;
    }
    
    void dfs(int v, int parent_v, vector <vector <int> > &G, vector <int> &component, int component_no)
    {
        component[v] = component_no;
        
        for(int child_v : G[v])
        {
            if(v == parent_v || component[child_v] != 0)
            {
                continue;
            }
            
            dfs(child_v, v, G, component, component_no);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        vector <vector <int>> graph(n + 1);
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        int component_no = 1;
        vector <int> component(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            if(component[i] == 0)
            {
                dfs(i, -1, graph, component, component_no);
                component_no++;
            }
        }
        
        vector <int> component_size(component_no + 1, 0);
        for(int i = 0; i < n; i++)
        {
            component_size[component[i]]++;
        }
        
        long long answer = choose_2(n);
        for(int i = 1; i < component_no; i++)
        {
            answer -= choose_2(component_size[i]);
        }
        return answer;
    }
};
