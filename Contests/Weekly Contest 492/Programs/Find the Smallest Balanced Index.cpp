#include <vector> 
using namespace std;

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) 
    {
        vector <long long> prefix_sum(nums.size()); 
        for(int i = 0; i < nums.size(); i++)
        {
            prefix_sum[i] = nums[i] + (i > 0 ? prefix_sum[i - 1] : 0);
        }

        int answer = -1; 
        long long product = 1;
        for(int i = nums.size() - 1; i >= 1; i--)
        {
            if(product == prefix_sum[i - 1])
            {
                answer = i;
            }

            long long new_sum = prefix_sum[i - 1] - nums[i - 1];
            if(new_sum/nums[i] < product)
            {
                break;
            }
            
            product *= nums[i];
        }
        
        return answer;
    }
};