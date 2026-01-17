#include <string> 
#include <vector> 
#define all(v) (v).begin(), (v).end()

using namespace std; 

class Solution 
{
    private: 

    char flip(char bit)
    {
        return (bit == '1' ? '0' : '1');
    }
    
    int parity(string &N)
    {
        int sum = 0;
        for(int i = 0; i < N.size(); i++)
        {
            sum += N[i] - '0';
            sum %= 2;
        }

        return sum;
    }

    void dfs(int v, 
             int parent_v, 
             int parent_edge_no,
             string &current, 
             string &target, 
             vector <vector <pair <int, int>> > &tree, 
             vector <int> &answer)
    {   
        for(int i = 0; i < tree[v].size(); i++)
        {
            int child_v = tree[v][i].second, edge_no = tree[v][i].first;
            if(child_v == parent_v)
            {
                continue;
            }
            
            dfs(child_v, v, edge_no, current, target, tree, answer); 
        }

        if(current[v] != target[v] && parent_v != -1)
        {
            answer.push_back(parent_edge_no);
            current[v] = flip(current[v]);
            current[parent_v] = flip(current[parent_v]);
        }
    }
    
    public:
    vector<int> minimumFlips(int no_of_vertices, vector<vector<int>>& edges, string start, string target) 
    {
        if(parity(start) != parity(target))
        {
            vector <int> not_possible(1, -1);
            return not_possible;
        }

        vector <vector <pair <int, int> > > tree(no_of_vertices + 1);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            tree[u].push_back(make_pair(i, v));
            tree[v].push_back(make_pair(i, u));
        }

        vector <int> answer_edges; 
        dfs(0, -1, -1, start, target, tree, answer_edges);

        sort(all(answer_edges));
        
        return answer_edges;
    }
};