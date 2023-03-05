class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        
        const int MAX_N = 1e6 + 5;
        vector <int> first(MAX_N, MAX_N), last(MAX_N, -1);
        for(int i = 0; i < nums.size(); i++)
        {
            first[nums[i]] = min(first[nums[i]], i);
            last[nums[i]] = max(last[nums[i]], i);
        }
        
        vector <int> left(MAX_N, MAX_N), right(MAX_N, -1);
        vector <int> no_of_divisors(MAX_N);
        for(int i = 2; i < MAX_N; i++)
        {
            if(no_of_divisors[i] > 0)
            {
                continue;
            }
            
            for(int multiple = i; multiple < MAX_N; multiple += i)
            {
                if(first[multiple] != MAX_N && last[multiple] != -1)
                {
                    left[i] = min(left[i], first[multiple]);
                    right[i] = max(right[i], last[multiple]);
                }
                
                no_of_divisors[multiple]++;
            }
        }
        
        vector <int> segments_starting(nums.size()), segments_ending(nums.size());
        for(int i = 2; i < MAX_N; i++)
        {
            if(left[i] != MAX_N && right[i] != -1)
            {
                segments_starting[left[i]]++;
                segments_ending[right[i]]++;
            }
        }
        
        int answer = -1;
        int open_segments = 0;
        for(int i = 0; i + 1 < nums.size(); i++)
        {
            open_segments += segments_starting[i];
            open_segments -= segments_ending[i];
            
            if(open_segments == 0)
            {
                answer = i;
                break;
            }
        }
        
        return answer;
    }
};
