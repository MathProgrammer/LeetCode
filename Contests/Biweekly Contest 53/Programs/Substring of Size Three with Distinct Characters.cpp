class Solution {
public:
    
    int is_same(char a, char b, char c)
    {
        return (a == b || b == c || c == a);
    }
    
    int countGoodSubstrings(string S) {
        
        int answer = 0;
        
        for(int i = 0; i + 2 < S.size(); i++)
        {
            if(is_same(S[i], S[i + 1], S[i + 2]) == false)
            {
                answer++;
            }
        }
        
        return answer;
    }
};
