const int MAX_N = 1e5 + 5;
vector <int> graph[MAX_N];

class Solution {
public:
    
    int ceil(int n, int d)
    {
        return (n/d) + (n%d != 0);
    }
    
    void dfs(int v, int parent_v, vector <int> &cars, vector <long long> &fuel, vector <int> &subtree, int seats)
    {
        subtree[v] = 1;
        
        int child_cars = 0;
        for(int i = 0; i < graph[v].size(); i++)
        {
            int child_v = graph[v][i]; 
            if(child_v == parent_v)
            {
                continue;
            }
            
            dfs(child_v, v, cars, fuel, subtree, seats);
            
            subtree[v] += subtree[child_v];
            cars[v] += cars[child_v];
            fuel[v] += fuel[child_v];
        }
        
        fuel[v] += cars[v];
        cars[v] = ceil(subtree[v], seats);
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int no_of_vertices = 0;
        for(int i = 0; i < roads.size(); i++)
        {
            no_of_vertices = max(no_of_vertices, roads[i][0]);
            no_of_vertices = max(no_of_vertices, roads[i][1]);
        }
        
        for(int i = 0; i <= no_of_vertices; i++)
        {
            graph[i].clear();
        }
        
        for(int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0], v = roads[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector <int> cars(roads.size() + 1);
        vector <long long> fuel(roads.size() + 1);
        vector <int> subtree(roads.size() + 1);
        dfs(0, -1, cars, fuel, subtree, seats);
        
        return fuel[0];
    }
};
