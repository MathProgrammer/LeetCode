class Solution 
{
    public:
    int countCollisions(string directions) 
    {
        string D; 
        
        int answer = 0;
        for(int i = 0; i < directions.size(); i++)
        {
            if(i + 1 < directions.size() && directions[i] == 'R' && directions[i + 1] == 'L')
            {
                D += 'S';
                answer += 2;
                i++;
            }
            else 
            {
                D += directions[i];
            }
        }
        
        int beginning_L = 0;
        for(int i = 0; i < D.size(); i++)
        {
            if(D[i] != 'L')
            {
                break;
            }
            
            beginning_L++;
        }
        
        int ending_R = 0;
        for(int i = D.size() - 1; i >= 0; i--)
        {
            if(D[i] != 'R')
            {
                break;
            }
            
            ending_R++;
        }
        
        for(int i = 0; i < D.size(); i++)
        {
            answer += (D[i] != 'S');
        }
        
        answer -= (beginning_L + ending_R);
        return answer;
    }
};
