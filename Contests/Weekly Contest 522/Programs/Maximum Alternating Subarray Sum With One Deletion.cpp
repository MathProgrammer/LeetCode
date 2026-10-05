#include <vector> 
#include <algorithm> 

using namespace std; 

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        const int ODD = 1, EVEN = 0; 
        const long long oo = 1e16;
        long long answer = -oo;
        vector <vector <long long> > max_sum_till(nums.size() + 1, vector <long long> (2));
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
            {
                max_sum_till[i][ODD] = nums[i];
                max_sum_till[i][EVEN] = -oo;
                answer = max(answer, max_sum_till[i][ODD]);
                continue;
            }

            max_sum_till[i][ODD] = nums[i] + max(0LL, max_sum_till[i - 1][EVEN]);
            max_sum_till[i][EVEN] = -nums[i] + max_sum_till[i - 1][ODD]; 

            answer = max(answer, max_sum_till[i][ODD]);
            answer = max(answer, max_sum_till[i][EVEN]);
        }

        vector <long long> max_sum_from(nums.size() + 1);
        vector <long long> min_sum_from(nums.size() + 1);
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i == nums.size() - 1)
            {
                max_sum_from[i] = max(0, nums[i]);
                min_sum_from[i] = min(0, nums[i]);
                continue;
            }

            max_sum_from[i] = max(0LL, nums[i] - min_sum_from[i + 1]);
            min_sum_from[i] = min(0LL, nums[i] - max_sum_from[i + 1]);
        }

        for(int i = 1; i + 1 < nums.size(); i++)
        {
            long long answer_here = max(
                max_sum_till[i - 1][EVEN] + max_sum_from[i + 1],
                max_sum_till[i - 1][ODD] - min_sum_from[i + 1]);

            answer = max(answer, answer_here);
        }
        
        return answer;
    }
};