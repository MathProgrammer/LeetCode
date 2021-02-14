class Solution 
{
    public:
    
    int minTrioDegree(int n, vector<vector<int>>& edges) 
    {
        vector <vector <int> > M(n + 1, vector <int> (n + 1, 0));
        vector <int> degree(n + 1, 0);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            
            M[u][v] = M[v][u] = 1;
            
            degree[u]++;
            degree[v]++;
        }
        
        const int oo = 1e9;
        int minimum_degree = oo;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1 + 1; j <= n; j++)
            {
                if(M[i][j] == 0)
                {
                    continue;
                }
                
                for(int k = j + 1; k <= n; k++)
                {
                    if(M[i][j] && M[j][k] && M[k][i])
                    {
                        int degree_trio = degree[i] + degree[j] + degree[k] - 6;
                        
                        minimum_degree = min(minimum_degree, degree_trio);
                    }
                }
            }
        }
        
        return (minimum_degree == oo ? -1 : minimum_degree);
    }
};
