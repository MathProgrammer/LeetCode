class Solution {
public:
    
    int alternating_sum(int n)
    {
        int sum = 0, multiplier = 1;
        while(n > 0)
        {
            int digit = n%10;
            sum += multiplier*digit; 
            
            multiplier *= -1;
            n /= 10;
        }
        
        return sum;
    }
    
    int reverse(int n)
    {
        int rev_n = 0;
        while(n > 0)
        {
            rev_n = rev_n*10 + n%10;
            n /= 10;
        }
        return rev_n;
    }
    
    int alternateDigitSum(int n) {
        return alternating_sum(reverse(n));
    }
};
