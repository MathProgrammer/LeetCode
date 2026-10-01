#include <vector> 
#include <set> 
using namespace std; 

class Solution
{
    private: 
    int is_present(set <int> &S, int left, int right)
    {
        auto it = S.upper_bound(left); 
        return (it != S.end() && *it <= right);
    }

    public:
    int longestSubarray(vector<int>& nums, int k) 
    {
        long long sum = 0; 
        int answer = 0;
        const int ABSENT = -2;
        vector <set <int>> indices(k);
        vector <int> earliest_occurence(k, ABSENT), latest_occurence(k, ABSENT);
        earliest_occurence[0] = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            long long current = nums[i];
            if(nums[i] < 0)
            {
                long long oo = 1e9;
                current += oo*k;
            }

            current %= k;
            
            sum += current; 
            sum %= k;

            if(earliest_occurence[sum] == ABSENT)
            {
                earliest_occurence[sum] = i;
            }
            latest_occurence[sum] = i;

            indices[current].insert(i);
        }

        for(int r = 0; r < k; r++)
        {
            for(int l = 0; l < k; l++)
            {
                if(earliest_occurence[l] == ABSENT || latest_occurence[r] == ABSENT)
                {
                    continue;
                }

                int segment_sum = (r - l + k)%k;
                int segment_length = latest_occurence[r] - earliest_occurence[l];

                if(segment_sum == 0)
                {
                    answer = max(answer, segment_length);
                    continue;
                }

                int r1 = (segment_sum%2 == 0 ? segment_sum/2 : -1); 
                int r2 = ((segment_sum + k)%2 == 0 ? (segment_sum + k)/2 : -1);
                
                if(r1 != -1 && is_present(indices[r1], earliest_occurence[l], latest_occurence[r]))
                {
                    answer = max(answer, segment_length);
                }

                if(r2 != -1 && is_present(indices[r2], earliest_occurence[l], latest_occurence[r]))
                {
                    answer = max(answer, segment_length);
                }
            }
        }

        return answer;
    }
};
