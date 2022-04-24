class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) 
    {
        const int MAX_Y = 101; 
        vector <vector <int> > X(MAX_Y);
        for(int i = 0; i < rectangles.size(); i++)
        {
            X[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        
        for(int y = 0; y < MAX_Y; y++)
        {
            sort(X[y].begin(), X[y].end());
        }
        
        vector <int> answer(points.size());
        for(int i = 0; i < points.size(); i++)
        {
            for(int y = points[i][1]; y < MAX_Y; y++)
            {
                int left = 0, right = X[y].size() - 1; 
                
                if(X[y].size() == 0)
                {
                    continue;
                }
                
                if(points[i][0] <= X[y][0])
                {
                    answer[i] += X[y].size(); 
                    continue;
                }
                
                if(points[i][0] > X[y].back())
                {
                    continue;
                }
                
                int first_equal_point = lower_bound(X[y].begin(), X[y].end(), points[i][0]) - X[y].begin();
                answer[i] += (X[y].size() - first_equal_point);
            }
        }
        
        return answer;
    }
};
