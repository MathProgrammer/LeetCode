#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution
{
    public:
    int minJumps(vector<int>& arr)
    {
        if(arr.size() == 1)
        {
            return 0;
        }
        
        map <int, vector <int> > indices;
        for(int i = 0; i < arr.size(); i++)
        {
            indices[arr[i]].push_back(i);
        }
        
        queue <int> Q;
        
        const int oo = 1e9 + 9;
        vector <int> steps(arr.size() + 5, oo);
        Q.push(0);
        steps[0] = 0;
        
        while(!Q.empty())
        {
            int x = Q.front();
            
            if(x == arr.size() - 1)
            {
                return steps[x];
            }
            
            Q.pop();
            
            vector <int> v = indices[arr[x]];
            for(int i = 0; i < v.size(); i++)
            {
                int child = v[i];
                
                if(steps[child] > steps[x] + 1)
                {
                    steps[child] = steps[x] + 1;
                    
                    Q.push(child);
                }
            }
            
            indices[x].clear();
            
            if(x - 1 >= 0 && steps[x - 1] >= steps[x] + 1)
            {
                steps[x - 1] = steps[x] + 1;
                
                Q.push(x - 1);
            }
            
            if(x + 1 <= arr.size() - 1 && steps[x + 1] >= steps[x] + 1)
            {
                steps[x + 1] = steps[x] + 1;
                
                Q.push(x + 1);
            }
        }
        
        return steps[arr.size() - 1];
    }
};
