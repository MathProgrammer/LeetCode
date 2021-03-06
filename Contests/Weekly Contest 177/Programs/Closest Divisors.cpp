#include <vector>

using namespace std;

class Solution
{
    public:
    
    void factorise(int n, int &x, int &y)
    {
        for(int i = 1; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                x = i;
                y = n/i;
            }
        }
    }
    
    vector<int> closestDivisors(int num)
    {
        const int oo = 1e9 + 9;
        int closest = oo;
        int x, y;
        
        int this_x, this_y;
        factorise(num + 1, this_x, this_y);
        
        if(abs(this_x - this_y) < closest)
        {
            x = this_x;
            y = this_y;
            
            closest = abs(x - y);
        }
        
        factorise(num + 2, this_x, this_y);
        
        if(abs(this_x - this_y) < closest)
        {
            x = this_x;
            y = this_y;
            
            closest = abs(x - y);
        }
        
        vector <int> answer;
        answer.push_back(x);
        answer.push_back(y);
        
        return answer;
    }
};
