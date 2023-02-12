class Solution {
public:
    
    int no_of_digits(int n)
    {
        int count = 0;
        while(n > 0)
        {
            count++;
            n /= 10;
        }
        
        return count;
    }
    
    int concatenate(int x, int y)
    {
        int digit_count = no_of_digits(y);
        for(int i = 1; i <= digit_count; i++)
        {
            x = x*10;
        }
        
        x += y;
        return x;
    }
    
    long long findTheArrayConcVal(vector<int>& nums) {
        long long answer = 0;
        for(int i = 0, j = nums.size() - 1; i <= j; i++, j--)
        {
            answer += (i == j ? nums[i] : concatenate(nums[i], nums[j]));
        }
        
        return answer;
    }
