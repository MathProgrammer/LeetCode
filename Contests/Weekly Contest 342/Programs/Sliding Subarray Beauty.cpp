class Solution {
public:
    
    int get_answer(map <int, int> &frequency, int x)
    {
        int frequency_so_far = 0;
        for(auto it = frequency.begin(); it != frequency.end(); it++)
        {
            frequency_so_far += (it->second);
            
            if(frequency_so_far >= x)
            {
                return (it->first);
            }
        }
        
        return 0;
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] = min(nums[i], 0);
        }
        
        vector <int> answer; 
        map <int, int> frequency;
        for(int left = 0, right = 0; right < nums.size(); right++)
        {
            frequency[nums[right]]++;
            if(right - left  + 1 < k)
            {
                continue;
            }
            
            int answer_here = get_answer(frequency, x);
            answer.push_back(answer_here);
            
            frequency[nums[left]]--;
            left++;
        }
        
        return answer;
    }
};
