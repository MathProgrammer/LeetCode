#include <vector> 
#include <algorithm> 
#include <map> 

using namespace std; 

class Solution {
    public:
        vector<bool> pathExistenceQueries(int no_of_vertices, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
        {
            vector <pair <int, int> > vertices; 
            for(int i = 0; i < nums.size(); i++)
            {
                vertices.push_back(make_pair(nums[i], i));
            }
            
            sort(vertices.begin(), vertices.end());
            sort(nums.begin(), nums.end());
            
            map <int, int> index; 
            for(int i = 0; i < vertices.size(); i++)
            {
                index[vertices[i].second] = i;
            }
    
            const int MAX_L = 20, oo = 1e9;
            vector <vector <int> > next(no_of_vertices + 1, vector <int> (MAX_L));
            next[no_of_vertices][0] = no_of_vertices;
            for(int i = no_of_vertices - 1; i >= 0; i--)
            {
                if(i == no_of_vertices - 1 || nums[i + 1] - nums[i] > maxDiff)
                {
                    next[i][0] = no_of_vertices;
                    continue;
                }
    
                int segment_end = upper_bound(nums.begin(), nums.end(), nums[i] + maxDiff) - nums.begin() - 1;
                next[i][0] = segment_end;
            }
            
            for(int l = 1; l < MAX_L; l++)
            {
                for(int v = 0; v <= no_of_vertices; v++)
                {
                    int next_stop = next[v][l - 1];
                    next[v][l] = next[next_stop][l - 1];
                }
            }
            
            vector <bool> is_reachable(queries.size(), false);
            for(int i = 0; i < queries.size(); i++)
            {
                int u = queries[i][0], v = queries[i][1]; 
                u = index[u], v = index[v];
    
                if(u > v)
                {
                    swap(u, v);
                }
    
                if(u == v)
                {
                    is_reachable[i] = true;
                    continue;
                }
    
                int path = 0;
                for(int l = MAX_L - 1; l >= 0 && u < v; l--)
                {
                    if(next[u][l] < v)
                    {
                        u = next[u][l];
                        path += (1 << l); 
                    }
                }

                u = next[u][0];
                is_reachable[i] = (u >= v);
            }
    
            return is_reachable;
        }
    };