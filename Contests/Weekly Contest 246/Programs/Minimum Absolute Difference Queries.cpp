class Solution {
public:
    vector<int> minDifference(vector<int> &A, vector<vector<int>>& queries) 
    {
        const int MAX_N = 101, N = 1e5 + 5;
        int no_of_elements = A.size();
        int frequency[MAX_N][N];
        //vector < vector <int> > frequency(MAX_N, vector <int> (no_of_elements + 1));
        memset(frequency, 0, sizeof(frequency));
        for(int i = 0; i < no_of_elements; i++)
        {
            if(i == 0)
            {
                frequency[A[i]][i]++;
                continue;
            }
            
            for(int x = 1; x < MAX_N; x++)
            {
                frequency[x][i] = frequency[x][i - 1];
            }
            frequency[A[i]][i]++;
        }
        
        vector <int> solution(queries.size(), MAX_N);
        for(int i = 0; i < queries.size(); i++)
        {   
            vector <int> distinct; 
            int left = queries[i][0], right = queries[i][1]; 
            
            for(int x = 1; x < MAX_N; x++)
            {
                int frequency_here = frequency[x][right] - (left > 0 ? frequency[x][left - 1] : 0);
                
                if(frequency_here > 0)
                {
                    distinct.push_back(x); 
                }
            }
            
            for(int j = 1; j < distinct.size(); j++)
            {
                solution[i] = min(solution[i], distinct[j] - distinct[j - 1]);
            }
            
            if(distinct.size() == 1)
            {
                solution[i] = -1;
            }
        }
        
        return solution;
    }
};
