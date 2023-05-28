lass Solution {
public:
    long long maxStrength(vector<int>& nums) 
    {
        int max_negative = -10, no_of_negative = 0, non_zero = 0;
        long long product = 1;
        for(int n : nums)
        {
            if(n == 0)
            {
                continue;
            }
            
            product *= n;
            non_zero++;
            
            if(n < 0)
            {
                max_negative = max(max_negative, n);
                no_of_negative++;
            }
        }
        
        if(no_of_negative%2 == 1)
        {
            product /= max_negative;
        }
        
        if(non_zero == 0)
        {
            product = 0;
        }
        
        if(non_zero == no_of_negative && no_of_negative == 1 && non_zero < nums.size())
        {
            product = 0;
        }
        
        if(no_of_negative == 1 && no_of_negative == nums.size())
        {
            product = max_negative; 
        }
        
        return product;
    }
};
