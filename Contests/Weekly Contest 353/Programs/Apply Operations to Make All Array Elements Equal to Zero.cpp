#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int no_of_elements = nums.size();
        vector <int> operations_starting(no_of_elements), operations_ending(no_of_elements), operations(no_of_elements);
        for(int i = 0; i < no_of_elements; i++)
        {
            if(i > 0)
            {
                operations[i] = operations[i - 1] + operations_starting[i] - operations_ending[i - 1];
            }
            
            if(i + k - 1 <= no_of_elements - 1)
            {
                int extra = max(0, nums[i] - operations[i]);
            
                operations_starting[i] += extra; 
                operations_ending[min(i + k - 1, no_of_elements - 1)] += extra;
                operations[i] += extra;
            }
          
            if(operations[i] != nums[i])
            {
                return false;
            }
        }
        
        return true;
    }
};
