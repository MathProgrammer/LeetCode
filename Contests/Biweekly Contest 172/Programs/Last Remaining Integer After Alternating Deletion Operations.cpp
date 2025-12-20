class Solution 
{
    private: 
    long long get_survivor_position(long long n, int is_left)
    {
        if(n == 1)
        {
            return 1;
        }
        
        int is_next_left = !is_left;
        if(is_left && n%2 == 0)
        {
            return 2*get_survivor_position(n/2, is_next_left);
        }

        return 2*get_survivor_position(n/2 + n%2, is_next_left) - 1;
    }
    
    public:
    long long lastInteger(long long n) 
    {
        return get_survivor_position(n, false);
    }
};