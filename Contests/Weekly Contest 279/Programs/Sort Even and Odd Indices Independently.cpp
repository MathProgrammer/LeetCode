class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) 
    {
        vector <int> even, odd; 
        for(int i = 0; i < nums.size(); i++)
        {
            switch(i%2)
            {
                case 0: even.push_back(nums[i]); break;
                case 1: odd.push_back(nums[i]); break;
            }
        }
        
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        
        vector <int> answer;
        for(int i = 0, j = 0; i < nums.size(); i++)
        {
            switch(i%2)
            {
                case 0: answer.push_back(even[j]); break;
                case 1 : answer.push_back(odd[j++]); break;
            }
        }
        
        return answer;
    }
};
