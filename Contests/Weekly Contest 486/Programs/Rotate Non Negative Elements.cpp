#include <vector> 

using namespace std; 
class Solution {
    private: 
    vector <int> rotate(vector <int> &A, int k)
    {
        int n = A.size();
        vector <int> answer(n); 
        if(n == 0)
        {
            return answer;
        }

        k %= n;
        for(int i = 0; i < n; i++)
        {
            int rotated_position = (i - k + n)%n;
            answer[rotated_position] = A[i];
        }
        
        return answer;
    }

    public:
    vector<int> rotateElements(vector<int>& nums, int k) 
    {
        vector <int> non_negative; 
        for(int n : nums)
        {
            if(n >= 0)
            {
                non_negative.push_back(n);
            }
        }

        vector <int> rotated_non_negative = rotate(non_negative, k); 

        vector <int> answer(nums.size()); 
        for(int i = 0, j = 0; i < nums.size(); i++)
        {
            if(nums[i] >= 0)
            {
                answer[i] = rotated_non_negative[j++];
            }
            else 
            {
                answer[i] = nums[i];
            }
        }

        return answer;
    }
};