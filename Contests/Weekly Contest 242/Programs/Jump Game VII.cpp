class Solution 
{
    public:
    
    int min(int a, int b)
    {
        return (a < b ? a : b);
    }
    
    bool canReach(string s, int minJump, int maxJump) 
    {
        vector <int> is_possible(s.size() + 1, false);
        vector <int> sum(s.size() + 5, 0);
        is_possible[s.size() - 1] = (s.back() == '0' ? true : false);
        sum[s.size() - 1] = is_possible[s.size() - 1];

        for(int i = s.size() - 2; i >= 0; i--)
        {
            int left = i + minJump;
            int right = min(i + maxJump, s.size() - 1); 
            
            int sum_here = (left <= right ? sum[left] - sum[right + 1] : 0); 
            
            is_possible[i] = (s[i] == '0' && sum_here > 0 ? true : false);
            sum[i] = (is_possible[i] + sum[i + 1]); 
        }
        
        return is_possible[0];
    }
};
