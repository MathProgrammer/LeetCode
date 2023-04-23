class Solution {
public:
    int minOperations(vector<int>& nums) {
        int frequency_1 = 0;
        int g = 0;
        for(int n : nums)
        {
            g = __gcd(g, n);
            frequency_1 += (n == 1);
        }
        
        if(g != 1)
        {
            return -1;
        }
        
        if(frequency_1 > 0)
        {
            return nums.size() - frequency_1;
        }
        
        int smallest_coprime_array = nums.size();
        vector <vector <int> > gcd(nums.size() + 1, vector <int> (nums.size() + 1));
        for(int length = 2; length <= nums.size(); length++)
        {
            for(int left = 0, right = left + length - 1; right < nums.size(); left++, right++)
            {
                if(length == 2)
                {
                    gcd[left][right] = __gcd(nums[left], nums[right]);
                }
                else 
                { 
                    gcd[left][right] = __gcd(nums[left], gcd[left + 1][right]);
                }
                
                if(gcd[left][right] == 1)
                {
                    smallest_coprime_array = min(smallest_coprime_array, length);
                    
                }
            }
        }
        
        int creating_first_1 = smallest_coprime_array - 1; cout << "S = " << smallest_coprime_array << "\n";
        int answer = nums.size() - 1 + creating_first_1;
        return answer;
    }
};
