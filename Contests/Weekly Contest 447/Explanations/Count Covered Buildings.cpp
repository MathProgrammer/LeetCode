#include <map> 
#include <vector> 
#include <algorithm> 

using namespace std; 

class Solution {
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& buildings) 
        {
            map <int, int> min_x_for_y, max_x_for_y, min_y_for_x, max_y_for_x; 
            for(int i = 0; i < buildings.size(); i++)
            {
                int x = buildings[i][0], y = buildings[i][1];
                max_x_for_y[y] = max(max_x_for_y[y], x);
                max_y_for_x[x] = max(max_y_for_x[x], y);
    
                if(min_y_for_x.count(x) == 0)
                {
                    min_y_for_x[x] = y;
                }
                else 
                {
                    min_y_for_x[x] = min(min_y_for_x[x], y);
                }
    
                if(min_x_for_y.count(y) == 0)
                {
                    min_x_for_y[y] = x;
                }
                else 
                {
                    min_x_for_y[y] = min(min_x_for_y[y], x);
                }
            }
    
            int answer = 0; 
            for(int i = 0; i <buildings.size(); i++)
            {
                int x = buildings[i][0], y = buildings[i][1]; 
                if(max_x_for_y[y] != x && 
                  max_y_for_x[x] != y && 
                  min_x_for_y[y] != x && 
                  min_y_for_x[x] != y)
                {
                    answer++;
                }
            }
    
            return answer;
        }
    };