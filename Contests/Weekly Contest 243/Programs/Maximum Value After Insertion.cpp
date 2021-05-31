class Solution {
public:
    
    string maximize(string n, int x)
    {
        string answer;
        string X = to_string(x);
        
        int best_position = 0;
        for(int i = 0; i < n.size(); i++)
        {
            if(n[i] >= X[0])
            {
                best_position++;
            }
            else
            {
                break;
            }
        }
        
        for(int i = 0; i < best_position; i++)
        {
            answer += n[i];
        }
        
        answer += X;
        
        for(int i = best_position; i < n.size(); i++)
        {
            answer += n[i];
        }
        
        return answer;
        
    }
    
    string minimize(string n, int x)
    {
        string answer;
        string X = to_string(x);
        
        int best_position = 1;
        for(int i = 1; i < n.size(); i++)
        {
            if(n[i] <= X[0])
            {
                best_position++;
            }
            else
            {
                break;
            }
        }
        
        
        for(int i = 0; i < best_position; i++)
        {
            answer += n[i];
        }
        
        answer += X;
        
        for(int i = best_position; i < n.size(); i++)
        {
            answer += n[i];
        }
        
        return answer;
        
    }
    
    string maxValue(string n, int x) {
        
        string answer;
        switch(n[0])
        {
            case '-' : answer = minimize(n, x); break;
            default : answer = maximize(n, x);
        }
        
        return answer;
    }
};
