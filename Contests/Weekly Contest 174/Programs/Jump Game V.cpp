#include <iostream>
#include <vector>

using namespace std;

class Solution
{

    public:
    
    vector <vector <int> > graph;
    vector <int> max_from;
    
    void dfs(int v)
    {
        if(max_from[v] != 0)
        {
            return;
        }
        
        max_from[v] = 1;
        
        for(int i = 0; i < graph[v].size(); i++)
        {
            int child_v = graph[v][i];
            
            dfs(child_v);
            
            max_from[v] = max(max_from[v], 1 + max_from[child_v]);
        }
    }
    
    int maxJumps(vector<int>& A, int d)
    {
        graph.resize(A.size() + 1);
        
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 1; j <= d && i + j < A.size(); j++)
            {
                if(A[i] <= A[i + j])
                {
                    break;
                }
                
                graph[i].push_back(i + j);
            }
            
            for(int j = 1; j <= d && i - j >= 0; j++)
            {
                if(A[i] <= A[i - j])
                {
                    break;
                }
                
                graph[i].push_back(i - j);
            }
        }
        
        max_from.resize(A.size() + 1);
        for(int i = 0; i < A.size(); i++)
        {
            if(max_from[i] == 0)
            {
                dfs(i);
            }
        }
        
        int answer = 0;
        for(int i = 0; i < A.size(); i++)
        {
            answer = max(answer, max_from[i]);
        }
        
        return answer;
    }
};
