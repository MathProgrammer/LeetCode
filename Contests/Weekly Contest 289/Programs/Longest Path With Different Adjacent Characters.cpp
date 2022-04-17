class Solution {
public:
    const int NO_OF_ALPHABETS = 26; 
    vector <vector <int> > tree;
    vector <vector <int> > best_child1, best_child2;
    vector <int> down_path, total_path;
    
    void refresh(int n)
    {
        down_path.resize(n);
        total_path.resize(n);
        
        tree.resize(n);
        
        best_child1.resize(n);
        best_child2.resize(n);
        
        for(int i = 0; i < n; i++)
        {
            tree[i].clear();
            
            down_path[i] = total_path[i] = 0;
            
            best_child1[i].resize(NO_OF_ALPHABETS);
            best_child2[i].resize(NO_OF_ALPHABETS);
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
            {
                best_child1[i][alpha] = best_child2[i][alpha] = 0;
            }
        }
    }
    
    void dfs(int v, string &s)
    {
        down_path[v] = 1; 
        
        for(int child_v : tree[v])
        {
            dfs(child_v, s);
            
            if(s[v] == s[child_v])
            {
                continue;
            }
            
            down_path[v] = max(down_path[v], 1 + down_path[child_v]);
            
            int alphabet = s[child_v] - 'a';
            
            if(down_path[child_v] > best_child1[v][alphabet])
            {
                best_child2[v][alphabet] = best_child1[v][alphabet];
                best_child1[v][alphabet] = down_path[child_v];
            }
            else if(down_path[child_v] > best_child2[v][alphabet])
            {
                best_child2[v][alphabet] = down_path[child_v];
            }
        }
        
        total_path[v] = down_path[v];
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            int path_1 = best_child1[v][alpha];
            int path_2 = best_child2[v][alpha];

            total_path[v] = max(total_path[v], path_1 + 1 + path_2);
        }
        
        int path_1 = 0, path_2 = 0; 
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            if(best_child1[v][alpha] > path_1)
            {
                path_2 = path_1;
                path_1 = best_child1[v][alpha];
            }
            else if(best_child1[v][alpha] > path_2)
            {
                path_2 = best_child1[v][alpha];
            }
        }
        total_path[v] = max(total_path[v], path_1 + 1 + path_2);
        
        //cout << "At " << v << " Down = " << down_path[v] << " Total = " << total_path[v] << "\n";
    }
    
    int longestPath(vector<int>& parent, string s) 
    {
        int no_of_vertices = parent.size(); 
        refresh(no_of_vertices + 1);
        
        for(int i = 1; i < no_of_vertices; i++)
        {
            tree[parent[i]].push_back(i);
        }
        
        dfs(0, s);
        
        int answer = 0;
        for(int i = 0; i < no_of_vertices; i++)
        {
            answer = max(answer, total_path[i]);
        }
        
        return answer;
    }
};
