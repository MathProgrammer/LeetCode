#include <vector> 
#include <algorithm> 
#include <queue> 

using namespace std; 
class Solution 
{
    private: 

    int min_3(int x, int y, int z)
    {
        return min(x, min(y, z));
    }

    int max_3(int x, int y, int z)
    {
        return max(x, max(y, z));
    }

    long long square(long long n)
    {
        return n*n;
    }
    
    int is_triplet(int x, int y, int z)
    {
        int a = min_3(x, y, z); 
        int c = max_3(x, y, z);
        int b = (x + y + z) - (a + c);


        return (square(c) == square(a) + square(b));
    }

    void bfs(vector <vector <int> > &tree, vector <int> &distance, int source)
    {
        const int oo = distance.size() + 1;
        for(int v = 0; v < distance.size(); v++)
        {
            distance[v] = oo;
        }
        distance[source] = 0;
        
        queue <int> Q; 
        Q.push(source);

        while(!Q.empty())
        {
            int v = Q.front();
            Q.pop();

            for(int child_v : tree[v])
            {
                int new_distance = distance[v] + 1;
                if(distance[child_v] > new_distance)
                {
                    distance[child_v] = new_distance; 
                    Q.push(child_v);
                }
            }
        }
    }
    
    public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) 
    {
        vector <vector <int> > tree(n); 
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1]; 
            tree[u].push_back(v); 
            tree[v].push_back(u);
        }

        vector <int> dx(n); bfs(tree, dx, x); 
        vector <int> dy(n); bfs(tree, dy, y); 
        vector <int> dz(n); bfs(tree, dz, z); 

        int special_nodes = 0;
        for(int v = 0; v < n; v++)
        {
            //cout << "v = " << v << " (" << dx[v] << "," << dy[v] << "," << dz[v] << "\n";
            special_nodes += is_triplet(dx[v], dy[v], dz[v]);
        }

        return special_nodes;
    }
};