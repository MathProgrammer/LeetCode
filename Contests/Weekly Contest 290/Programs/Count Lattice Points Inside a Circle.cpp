class Solution {
public:
    int square(int n)
    {
        return n*n;
    }
    
    int countLatticePoints(vector<vector<int>>& circles) 
    {
        int answer = 0;
        map <pair <int, int>, int> counted; 
        for(int i = 0; i < circles.size(); i++)
        {
            int X = circles[i][0], Y = circles[i][1], R = circles[i][2];
            for(int x = X - R; x <= X + R; x++)
            {
                for(int y = Y - R; y <= Y + R; y++)
                {
                    if(counted[make_pair(x, y)])
                    {
                        continue;
                    }
                    
                    if(square(x - X) + square(y - Y) <= square(R))
                    {
                        counted[make_pair(x, y)] = true;
                        
                        answer++;
                    }
                }
            }
        }
        
        return answer;
    }
};
