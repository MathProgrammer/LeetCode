class Solution {
public:
    
    string to_string(int n)
    {
        string N; 
        
        if(n == 0)
        {
            N = "0";
        }
        
        while(n > 0)
        {
            N += (char)('0' + n%10);
            n /= 10;
        }
        
        reverse(N.begin(), N.end());
        
        return N;
    }
    
    string digitSum(string s, int k) 
    {
        int sum = 0;
        string answer = s; 
        while(s.size() > k)
        {
            answer = "";
            
            for(int i = 0; i < s.size(); i++)
            {
                sum += s[i] - '0';
                if( (i + 1)%k == 0 || i + 1 == s.size())
                {
                    answer += to_string(sum);
                    sum = 0;
                }
            }
            
            s = answer;
        }
        
        return answer;
    }
};
