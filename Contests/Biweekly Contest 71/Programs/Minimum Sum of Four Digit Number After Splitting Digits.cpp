class Solution 
{
    public:
    
    int minimumSum(int num) 
    {
        int prefix = 0, suffix = 0, suffix_digits = 0;
        int answer = 1e5;
        vector <int> D(4);
        for(int i = 0; i < 4 && num > 0; i++)
        {
            D[i] = num%10;
            num /= 10;
        }
        
        sort(D.begin(), D.end());
        
        int x = D[0]*10 + D[2], y = D[1]*10 + D[3];
        
        return x + y;
    }
};
