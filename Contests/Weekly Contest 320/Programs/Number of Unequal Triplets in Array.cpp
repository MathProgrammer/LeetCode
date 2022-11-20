class Solution {
public:
    int unequalTriplets(vector<int>& nums) 
    {
        const int MAX = 1000;
        vector <int> frequency(MAX + 5, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++;
        }
        
        vector <int> prefix_no_of_ways(MAX + 5, 0);
        for(int i = 1; i <= MAX; i++)
        {
            prefix_no_of_ways[i] =  prefix_no_of_ways[i - 1] + frequency[i];
        }
        
        vector <int> suffix_no_of_ways(MAX + 5, 0);
        for(int i = MAX; i >= 1; i--)
        {
            suffix_no_of_ways[i] = suffix_no_of_ways[i + 1] + frequency[i];
        }
        
        int answer = 0;
        for(int i = 1; i < MAX; i++)
        {
            answer += prefix_no_of_ways[i - 1]*frequency[i]*suffix_no_of_ways[i + 1];
        }
        
        return answer;
    }
};
