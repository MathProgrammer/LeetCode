#include <vector>

using namespace std;

class Solution
{
    public:
    
    void reduce(vector <int> &frequency, int sum)
    {
        for(int d = 0; d <= 9; d++)
        {
            if(frequency[d] > 0 && d%3 == sum)
            {
                frequency[d]--;
                return;
            }
        }
        
        for(int d1 = 0; d1 <= 9; d1++)
        {
            for(int d2 = d1; d2 <= 9; d2++)
            {
                if(d1 == d2)
                {
                    if(frequency[d1] >= 2 && (d1 + d2)%3 == sum)
                    {
                        frequency[d1]--;
                        frequency[d2]--;
                        
                        return;
                    }
                    
                    continue;
                }
                
                if(frequency[d1] > 0 && frequency[d2] > 0 && (d1 + d2)%3 == sum)
                {
                    frequency[d1]--;
                    frequency[d2]--;
                    
                    return;
                }
            }
        }
    }
    
    string largestMultipleOfThree(vector<int>& digits)
    {
        const int NO_OF_DIGITS = 10;
        vector <int> frequency(NO_OF_DIGITS, 0);
        
        for(int i = 0; i < digits.size(); i++)
        {
            frequency[digits[i]]++;
        }
        
        string answer;
        long long sum = 0;
        vector <int> chosen_frequency(NO_OF_DIGITS, 0);
        for(int d = 0; d <= 9; d++)
        {
            chosen_frequency[d] = frequency[d];
            
            sum += (d*frequency[d])%3;
        }
        
        sum %= 3;
        
        switch(sum)
        {
            case 1 : reduce(chosen_frequency, sum);
                     break;
                
            case 2 : reduce(chosen_frequency, sum);
                     break;
        }
        
        for(int d = NO_OF_DIGITS - 1; d >= 0; d--)
        {
            for(int i = 1; i <= chosen_frequency[d]; i++)
            {
                answer += (char)('0' + d);
            }
        }
        
        if(answer[0] == '0' && answer.back() == '0' && answer.size() > 1)
        {
            answer = "0";
        }
        
        return answer;
    }
};
