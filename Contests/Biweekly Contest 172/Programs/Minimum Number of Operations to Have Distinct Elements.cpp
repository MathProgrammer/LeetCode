#include <set> 
#include <vector>

using namespace std;

class Solution {
    private: 
    int ceil(int numerator, int denominator)
    {
        return numerator/denominator + (numerator%denominator != 0);
    }
    
    public:
    int minOperations(vector<int>& nums) 
    {
        int distinct_suffix_size = 1;
        set <int> suffix_elements;
        for(int i = nums.size() - 1; i >= 0; i--, distinct_suffix_size++)
        {
            suffix_elements.insert(nums[i]);
            if(suffix_elements.size() != distinct_suffix_size)
            {
                break;
            }
        }

        distinct_suffix_size--;

        int prefix = nums.size() - distinct_suffix_size; 
        int operations = ceil(prefix, 3);

        return operations;
    }
};