#define all(v) (v).begin(), (v).end()

class Solution {
public:
    
    int digit_sum(int n)
    {
        int sum = 0;
        
        while(n > 0)
        {
            sum += n%10;
            n /= 10;
        }
        
        return sum;
    }
    
    int maximumSum(vector<int>& nums) 
    {
        const int MAX_SUM = 85;
        vector <int> numbers_with_sum[MAX_SUM];   
        for(int i = 0; i < nums.size(); i++)
        {
            numbers_with_sum[digit_sum(nums[i])].push_back(nums[i]);
        }
        
        int answer = -1;
        for(int digit_sum = 0; digit_sum < MAX_SUM; digit_sum++)
        {
            sort(all(numbers_with_sum[digit_sum]));
            reverse(all(numbers_with_sum[digit_sum]));
                 
             if(numbers_with_sum[digit_sum].size() >= 2)
             {
                    answer = max(answer, numbers_with_sum[digit_sum][0] + numbers_with_sum[digit_sum][1]);
             }
        }
                    
        return answer;
    }
};
