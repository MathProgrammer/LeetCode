class Solution {
public:
    string removeTrailingZeros(string num) {
        int last_non_0 = num.size() - 1;
        while(last_non_0 >= 0 && num[last_non_0] == '0')
        {
            last_non_0--;
        }
        
        string answer; 
        for(int i = 0; i <= last_non_0; i++)
        {
            answer += num[i];
        }
        
        return answer;
    }
};
