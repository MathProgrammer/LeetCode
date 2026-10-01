#include <vector> 
#include <map> 

using namespace std; 

class Solution 
{
public:
    int longestSubarray(vector<int>& nums, int k) 
    {
        vector <long long> sum(nums.size(), 0);
        int answer = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            long long current = nums[i];
            if(nums[i] < 0)
            {
                long long oo = 1e9;
                current += oo*k;
                current %= k;
            }

            sum[i] = (i == 0 ? 0 : sum[i - 1]);
            sum[i] += current; 
            sum[i] %= k;
        }

        map <int, int> last;
        for(int r = 0; r < nums.size(); r++)
        {
            long long current = nums[r];
            if(nums[r] < 0)
            {
                long long oo = 1e9;
                current += oo*k;
            }

            current %= k; 
            last[current] = r;
            
            for(int l = 0; l <= r; l++)
            {
                int segment_length = r - l + 1;
                int segment_sum = sum[r] - (l == 0 ? 0 : sum[l - 1]) + k; 
                segment_sum %= k;

                int r1 = (segment_sum%2 == 0 ? segment_sum/2 : -1); 
                int r2 = ((segment_sum + k)%2 == 0 ? (segment_sum + k)/2 : -1);
                //cout << "Segment Length = " << l << "," << r << "] S = " << segment_sum << " R1 = " << r1 << " R2 = " << r2 << "\n";

                if(segment_sum == 0)
                {
                    answer = max(answer, segment_length);
                }

                if(r1 != -1 && last.count(r1) != 0 && last[r1] >= l)
                {
                    answer = max(answer, segment_length);
                }

                if(r2 != -1 && last.count(r2) != 0 && last[r2] >= l)
                {
                    answer = max(answer, segment_length);
                }
            }
        }

        return answer;
    }
};
