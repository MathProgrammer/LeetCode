class Solution {
public:
    int countOperations(int num1, int num2) 
    {
        int operations = 0;
        while(min(num1, num2) > 0)
        {
            if(num1 < num2)
            {
                swap(num1, num2);
            }
            
            operations += num1/num2;
            num1 %= num2;
        }
        
        return operations;
    }
};
