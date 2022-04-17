#define all(v) (v).begin(), (v).end()

class Solution 
{
    public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) 
    {
        int no_of_vertices = scores.size();
        vector <vector < pair<int, int> >  > score_pairs(no_of_vertices);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            
            int sum = scores[u] + scores[v];
            
            score_pairs[u].push_back(make_pair(sum, v));
            score_pairs[v].push_back(make_pair(sum, u));
        }
        
        for(int i = 0; i < no_of_vertices; i++)
        {
            sort(all(score_pairs[i]));
            
            reverse(all(score_pairs[i]));
        }
        
        int answer = -1;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            
            if(score_pairs[u].size() < 2 || score_pairs[v].size() < 2)
            {
                continue;
            }
            
            if(score_pairs[u].size() > 2 && score_pairs[v].size() == 2)
            {
                swap(u, v);
            }
            
            int w = score_pairs[u][0].second, x = score_pairs[v][0].second;
            
            if(w == v)
            {
                w = score_pairs[u][1].second;
            }
            
            for(int j = 0; j < score_pairs[v].size(); j++)
            {
                int neighbour = score_pairs[v][j].second;
                if(neighbour == u || neighbour == w)
                {
                    continue;
                }
                
                x = neighbour;
                break;
            }
            
            if(x == u || x == w)
            {
                continue;
            }
            
            int sum_here = scores[u] + scores[v] + scores[w] + scores[x]; 
            
            answer = max(answer, sum_here);
        }
        
        return answer;
    }
};
