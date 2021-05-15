class Solution 
{
public:
    vector<int> memLeak(int memory1, int memory2) 
    {
        vector <int> answer;
        
        int time = 1;
        for(time = 1; max(memory1, memory2) >= time; time++)
        {
            if(memory1 >= memory2)
            {
                memory1 -= time;
            }
            else 
            {
                memory2 -= time;
            }
        }
        
        answer.push_back(time);
        answer.push_back(memory1);
        answer.push_back(memory2);
        
        return answer;
    }
};
