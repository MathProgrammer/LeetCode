class Solution {
public:
    void factorise(int n, vector <int> &factors)
    {
        for(int i = 2; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                factors.push_back(i);
                
                while(n%i == 0)
                {
                    n /= i;
                }
            }
        }
        
        if(n > 1)
        {
            factors.push_back(n);
        }
    }
    
    void dfs(int v, vector <vector <int> > &graph, vector <int> &visited)
    {
        if(visited[v])
        {
            return;
        }
        visited[v] = true;
        
        for(int child_v : graph[v])
        {
            if(!visited[child_v])
            {
                dfs(child_v, graph, visited);
            }
        }
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        
        set <int> N; 
        for(int n : nums)
        {
            N.insert(n);
        }
        
        const int MAX_N = 1e5 + 5;
        
        int has_1 = false;
        vector <vector <int> > graph(MAX_N);
        set <int> vertices; 
        for(int n : N)
        {
            if(n == 1)
            {
                has_1 = true;
            }
            
            vector <int> prime_factors; 
            factorise(n, prime_factors);
            
            for(int p : prime_factors)
            {
                vertices.insert(p);
            }
            
            for(int i = 0; i < prime_factors.size(); i++)
            {
                for(int j = i + 1; j < prime_factors.size(); j++)
                {
                    int u = prime_factors[i], v = prime_factors[j];
                    //cout << "Edge " << u << "-" << v << "\n";
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }
        
        int no_of_components = 0;
        vector <int> visited(MAX_N, false);
        for(int v : vertices)
        {
            if(vertices.count(v) > 0 && !visited[v])
            {
                dfs(v, graph, visited);
                no_of_components++;
            }
        }
        
        if(nums.size() == 1)
        {
            return true;
        }
        
        return (!has_1 && no_of_components == 1 ? true : false);
    }
};
