class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        int answer = -1;
        for(int i = 0; i < number.size(); i++)
        {
            if(number[i] == digit && number[i] < number[i + 1])
            {
                answer = i; 
                break;
            }
        }
                                            
        if(answer == -1)
        {
            for(int i = number.size() - 1; i >= 0; i--)
            {
                if(number[i] == digit)
                {
                    answer = i;
                    break;
                }
            }
        }
        
        string result; 
        for(int i = 0; i < number.size(); i++)
        {
            if(i == answer)
            {
                continue;
            }
            
            result += number[i];
        }
        
        return result;
    }
};
