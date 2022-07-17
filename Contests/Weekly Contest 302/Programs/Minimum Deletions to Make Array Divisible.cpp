class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) 
    {
        int array_gcd = 0;
        for(int x : numsDivide)
        {
            array_gcd = __gcd(array_gcd, x);
        }
        
        sort(nums.begin(), nums.end());
        
        int first_good_element = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(array_gcd%nums[i] == 0)
            {
                first_good_element = i;
                break;
            }
        }
        
        return first_good_element;
    }
};
