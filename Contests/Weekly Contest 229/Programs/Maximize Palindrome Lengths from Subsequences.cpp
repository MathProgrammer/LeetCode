class Solution 
{

    public:
    
    void get_LPS(string &S, vector <vector <int> > &LPS)
    {
        for(int length = 1; length < S.size(); length++)
        {
            for(int left = 0, right = left + length - 1; right < S.size(); left++, right++)
            {
                if(length == 1)
                {
                    LPS[left][right] = 1;
                    continue;
                }
                
                LPS[left][right] = max(LPS[left + 1][right], LPS[left][right - 1]);
        
                if(S[left] == S[right])
                {
                    LPS[left][right] = max(LPS[left][right], 2 + LPS[left + 1][right - 1]);
                }
            }
        }
    }

    int longestPalindrome(string A, string B) 
    {
        int n = A.size() + B.size();
        string combined = A + B;
        vector < vector <int> > LPS(n + 1, vector <int> (n + 1, 0));
        get_LPS(combined, LPS); 
        
        int answer = 0;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < B.size(); j++)
            {
                if(A[i] == B[j])
                {
                    int palindrome_here = 2 + LPS[i + 1][A.size() + j - 1];
                    
                    answer = max(answer, palindrome_here);
                }
            }
        }
        
        return answer;
    }
};
