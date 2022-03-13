class Solution 
{
    public:
    
    struct Edge 
    {
        int destination;
        long long weight; 
        
        Edge();
            
        Edge(int D, long long W)
        {
            destination = D;
            weight = W;
        }
    };
    
    void bfs(vector < vector <pair <int, long long> > > &graph, int source, vector <long long> &distance)
    {
        distance[source] = 0;
        priority_queue <pair <long long, int> > PQ;
        PQ.push(make_pair(distance[source], source));
        
        while(!PQ.empty())
        {
            int v = PQ.top().second;
            long long current_distance_v = PQ.top().first;
            PQ.pop(); 
            
            if(current_distance_v > distance[v])
            {
                continue;
            }
            
            for(pair <int, long long> edges_v : graph[v])
            {
                int child_v = edges_v.first;
                long long child_weight = edges_v.second;
                
                if(distance[v] + child_weight  < distance[child_v])
                {
                    distance[child_v] = distance[v] + child_weight;
                    PQ.push(make_pair(distance[child_v], child_v));
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vector < vector <pair <int, long long> > > graph(n), reverse_graph(n); 
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            long long weight = edges[i][2];
            
            graph[u].push_back(make_pair(v, weight));
            reverse_graph[v].push_back(make_pair(u, weight));
        }
        
        const long long oo = 1e17;
        vector <long long> source_1_distance(n + 1, oo), source_2_distance(n + 1, oo), destination_distance(n + 1, oo);
        bfs(graph, src1, source_1_distance);
        bfs(graph, src2, source_2_distance);
        bfs(reverse_graph, dest, destination_distance);
        
        long long answer = oo;
        for(int common_vertex = 0; common_vertex < n; common_vertex++)
        {
            answer = min(answer, source_1_distance[common_vertex] + source_2_distance[common_vertex] + destination_distance[common_vertex]);
        }
        
        return (answer == oo ? -1 : answer);
    }
};
