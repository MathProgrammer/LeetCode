class Solution 
{
    public:
    vector<int> minOperations(string boxes) 
    {
        vector <int> prefix_balls(boxes.size(), 0);
        vector <int> prefix_time(boxes.size(), 0);
        prefix_balls[0] = (boxes[0] == '1');
        for(int i = 1; i < boxes.size(); i++)
        {
            prefix_balls[i] = prefix_balls[i - 1] + (boxes[i] == '1');
            
            prefix_time[i] = prefix_time[i - 1] + prefix_balls[i - 1];
        }
        
        vector <int> suffix_balls(boxes.size() + 5, 0);
        vector <int> suffix_time(boxes.size() + 5, 0);
        for(int i = boxes.size() - 1; i >= 0; i--)
        {
            suffix_balls[i] = suffix_balls[i + 1] + (boxes[i] == '1');
            
            suffix_time[i] = suffix_time[i + 1] + suffix_balls[i + 1];
        }
        
        vector <int> answer(boxes.size(), 0);
        for(int i = 0; i < boxes.size(); i++)
        {
            answer[i] = prefix_time[i] + suffix_time[i];
        }
        
        return answer;
    }
};
