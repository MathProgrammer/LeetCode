class Solution 
{
    public:
    
    void dfs(vector <vector <int> > &tree, vector <int> &H, vector <int> &A, vector <int> &answer, vector < stack <pair <int, int> > > &index, int v, int parent_v)
    {
        const int MAX_N = 55;
        int ancestor_distance = 0;
        for(int i = 1; i < MAX_N; i++)
        {
            if(__gcd(i, A[v]) > 1 || index[i].size() == 0)
            {
                continue;
            }
            
            pair <int, int> current = index[i].top();
            
            if(current.second > ancestor_distance)
            {
                ancestor_distance = current.second;
                
                answer[v] = current.first;
            }
        }
        
        index[A[v]].push(make_pair(v, H[v]));
        
        for(int child_v : tree[v])
        {
            if(child_v == parent_v)
            {
                continue;
            }
            
            H[child_v] = H[v] + 1;
            
            dfs(tree, H, A, answer, index, child_v, v);
        }
        
        index[A[v]].pop();
    }
    
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n = nums.size();
        vector <vector <int> > tree(n + 1);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        vector <int> height(n + 1, 0);
        height[0] = 1;
    
        const int MAX_VALUE = 55;
        vector < stack <pair <int, int> > > index(MAX_VALUE);
        
        vector <int> answer(n, -1);
        
        dfs(tree, height, nums, answer, index, 0, -1);
        
        return answer;
    }
};
