class Solution 
{
    public:
    
    int min_first(string &s, char first)
    {
        int operations = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(i%2 == 0 && s[i] != first)
            {
                operations++;
            }
            else if(i%2 == 1 && s[i] == first)
            {
                operations++;
            }
        }
        
        return operations;
    }
    
    int minOperations(string s) 
    {
        return min(min_first(s, '0'), min_first(s, '1'));
    }
};
