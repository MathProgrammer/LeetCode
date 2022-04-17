class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        map <int, int> frequency; 
        for(int i = 0; i < tasks.size(); i++)
        {
            frequency[tasks[i]]++;
        }
        
        int answer = 0;
        for(auto it = frequency.begin(); it != frequency.end(); it++)
        {
            if(it->second == 1)
            {
                answer = -1;
                break;
            }
            
            switch( (it->second)%3 )
            {
                case 0: answer += it->second/3; break; 
                case 1: answer += (it->second - 4)/3 + 2; break; 
                case 2: answer += (it->second - 2)/3 + 1; break;
            }
        }
        
        return answer;
    }
};
