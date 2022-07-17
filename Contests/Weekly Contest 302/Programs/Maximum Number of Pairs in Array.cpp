class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) 
    {
        const int MAX = 101;
        vector <int> frequency(MAX, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++;
        }
        
        vector <int> answer(2);
        for(int i = 0; i < MAX; i++)
        {
            if(frequency[i] >= 2)
            {
                answer[0] += frequency[i]/2;
            }
            
            if(frequency[i]%2 == 1)
            {
                answer[1]++;
            }
        }
        
        return answer;
    }
};
