#include <vector> 
using namespace std; 

class DSU
{
    int no_of_vertices, no_of_components;
    vector <int> parent; 
    
    public :
    DSU(int n)
    {
        no_of_components = n;
        no_of_vertices = n; 
        
        parent.resize(no_of_vertices + 1); 
        for(int v = 0; v < no_of_vertices; v++)
        {
            parent[v] = v;
        }
    }

    int get_component_count()
    {
        return no_of_components;
    }
    
    int get_parent(int v)
    {
        while(parent[v] != v)
        {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        
        return parent[v];
    }
    
    void combine(int u, int v)
    {
        u = get_parent(u); 
        v = get_parent(v);
        
        if(u == v)
        {
            return;
        }

        no_of_components--;
        parent[u] = v;
    }
};

class Solution 
{
    public:
    int countComponents(vector<int>& nums, int threshold)
    {
        DSU dsu(nums.size());
        const int NO_COMPONENT = -1;
        vector <int> component(threshold + 1, NO_COMPONENT); 

        sort(nums.begin(), nums.end()); 
        
        for(int i = 0; i < nums.size() && nums[i] <= threshold; i++)
        {
            for(int multiple = nums[i]; multiple <= threshold; multiple += nums[i])
            {
                if(component[multiple] == NO_COMPONENT)
                {
                    component[multiple] = i;
                }
                else 
                {
                    dsu.combine(i, component[multiple]);
                }
            }
        }

        return dsu.get_component_count();
    }
};