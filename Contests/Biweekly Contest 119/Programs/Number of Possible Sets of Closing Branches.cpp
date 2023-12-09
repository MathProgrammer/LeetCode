class Solution {
public:
    
    int is_bit_set(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }
    
    void build(vector <vector <int> > &distance, vector <vector <int> > &roads, int mask)
    {
        const int oo = 1e5;
        for(int i = 0; i < distance.size(); i++)
        {
            for(int j = i; j < distance.size(); j++)
            {
                distance[i][j] = distance[j][i] = oo;
            }
        }
        
        for(int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0], v = roads[i][1], d = roads[i][2]; 
            
            if(is_bit_set(mask, u) || is_bit_set(mask, v))
            {
                continue;
            }
            
            distance[u][v] = min(distance[u][v], d);
            distance[v][u] = distance[u][v];
        }
    }
    
    void floyd_warhsall(vector <vector <int> > &distance, int mask)
    {
        for(int k = 0; k < distance.size(); k++)
        {
            for(int i = 0; i < distance.size(); i++)
            {
                for(int j = 0; j < distance.size(); j++)
                {
                    if(is_bit_set(mask, i) || is_bit_set(mask, j) || is_bit_set(mask, k))
                    {
                        continue;
                    }
                    
                    if(distance[i][j] > distance[i][k] + distance[k][j])
                    {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    } 
    
    int maximum(vector <vector <int> > &distance, int mask)
    {
        int max_distance = 0; 
        for(int u = 0; u < distance.size(); u++)
        {
            for(int v = u + 1; v < distance.size(); v++)
            {
                if(is_bit_set(mask, u) || is_bit_set(mask, v))
                {
                    continue;
                }
                
                max_distance = max(max_distance, distance[u][v]);
            }
        }
        
        return max_distance;
    }
    
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) 
    {
        int good_sets = 0;
        vector <vector <int> > distance(n, vector <int> (n)); 
        for(int m = 0, max_mask = (1 << n); m < max_mask; m++)
        {
            build(distance, roads, m); 
            
            floyd_warhsall(distance, m); 
            
            if(maximum(distance, m) <= maxDistance)
            {
                good_sets++;
            }
        }
        
        return good_sets;
    }
};
