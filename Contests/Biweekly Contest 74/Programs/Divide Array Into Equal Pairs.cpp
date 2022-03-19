class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        map <int, int> frequency; 
        for(int num : nums)
        {
            frequency[num]++;
        }
        
        int possible = true;
        for(int num : nums)
        {
            if(frequency[num]%2 == 1)
            {
                possible = false;
            }
        }
        
        return possible;
    }
};
