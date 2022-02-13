class Solution 
{
    public:
    
    int digits_set(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            sum += (n%3);
            n /= 3;
        }
        
        return sum;
    }
    
    int get_tribit(int n, int digit)
    {
        while(digit > 0)
        {
            n /= 3;
            digit--;
        }
        
        return (n%3);
    }
    
    int power(int x, int p)
    {
        int result = 1;
        for(int i = 1; i <= p; i++)
        {
            result *= x;
        }
        return result;
    }
    
    int maximumANDSum(vector<int> &A, int numSlots) 
    {
        const int MAX_MASK = power(3, numSlots);
        vector <vector <int> > maximum_sum(A.size() + 1, vector <int> (MAX_MASK, 0));
        for(int i = 0; i < A.size(); i++)
        {
            for(int m = 0; m < MAX_MASK; m++)
            {
                for(int tribit = 0; tribit < numSlots; tribit++)
                {
                    int current_tribit = get_tribit(m, tribit);
                    
                    if(current_tribit == 0 || digits_set(m) != i + 1)
                    {
                        continue;
                    }
                    
                    int current_AND = (A[i]&(tribit + 1));
                    int old_m = m - power(3, tribit);
                    
                    if(i == 0)
                    {
                        maximum_sum[i][m] = current_AND;
                    }
                    else 
                    {
                        maximum_sum[i][m] = max(maximum_sum[i][m], current_AND + maximum_sum[i - 1][old_m]);
                    }
                }
            }
        }
        
        int answer = 0;
        for(int m = 0; m < MAX_MASK; m++)
        {
            if(digits_set(m) == A.size())
            {
                answer = max(answer, maximum_sum[A.size() - 1][m]);
            }
        }
        
        return answer;
    }
};
