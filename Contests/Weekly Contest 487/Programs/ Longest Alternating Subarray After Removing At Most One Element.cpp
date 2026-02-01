#include <cstring>
#include <algorithm>
#include <vector>

using namespace std; 

class Solution {
public:
    int longestAlternating(vector<int>& nums) 
    {
        const int DOWN = 0, UP = 1, NO_DELETE = 0, ONE_DELETE = 1;
        int longest_subarray[nums.size()][2][2];
        memset(longest_subarray, 0, sizeof(longest_subarray));
        
        longest_subarray[0][NO_DELETE][UP] = longest_subarray[0][NO_DELETE][DOWN] = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            longest_subarray[i][NO_DELETE][UP] = longest_subarray[i][NO_DELETE][DOWN] = 1;
            if(nums[i - 1] < nums[i])
            {
                longest_subarray[i][NO_DELETE][UP] = max(
                    longest_subarray[i][NO_DELETE][UP], 
                    1 + longest_subarray[i - 1][NO_DELETE][DOWN]); 
                
                longest_subarray[i][ONE_DELETE][UP] = max(
                    longest_subarray[i][ONE_DELETE][UP], 
                    1 + longest_subarray[i - 1][ONE_DELETE][DOWN]); 
            }

            if(nums[i - 1] > nums[i])
            {
                longest_subarray[i][NO_DELETE][DOWN] = max(
                    longest_subarray[i][NO_DELETE][DOWN], 
                    1 + longest_subarray[i - 1][NO_DELETE][UP]); 
                
                longest_subarray[i][ONE_DELETE][DOWN] = max(
                    longest_subarray[i][ONE_DELETE][DOWN], 
                    1 + longest_subarray[i - 1][ONE_DELETE][UP]); 
            }

            if(i >= 2 && nums[i - 2] < nums[i])
            {
                longest_subarray[i][ONE_DELETE][UP] = max(
                    longest_subarray[i][ONE_DELETE][UP], 
                    1 + longest_subarray[i - 2][NO_DELETE][DOWN]); 
            }

            if(i >= 2 && nums[i - 2] > nums[i])
            {
                longest_subarray[i][ONE_DELETE][DOWN] = max(
                    longest_subarray[i][ONE_DELETE][DOWN], 
                    1 + longest_subarray[i - 2][NO_DELETE][UP]); 
            }
        }

        int answer = 0; 
        for(int i = 0; i < nums.size(); i++)
        {
            for(int deletes = 0; deletes <= 1; deletes++)
            {
                for(int direction = DOWN; direction <= UP; direction++)
                {
                    answer = max(answer, longest_subarray[i][deletes][direction]);
                }
            }
        }

        return answer;
    }
};