class Solution {
public:
    string largestOddNumber(string num) 
    {
        int end_point = -1;
        for(int i = num.size() - 1; i >= 0; i--)
        {
            if( (num[i] - '0')%2 == 1 )
            {
                end_point = i;
                break;
            }
        }
        
        string answer;
        for(int i = 0; i <= end_point; i++)
        {
            answer += num[i];
        }
        
        return answer;
    }
};
