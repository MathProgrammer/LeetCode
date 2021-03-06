#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    int no_of_elements = nums.size() , longest_increasing_subsequence = 0;

    vector <int> element(no_of_elements);
    vector <int> longest_increasing_subsequence_till_here(no_of_elements, 1);

    for(int i = 0; i < no_of_elements; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i])
            {
                longest_increasing_subsequence_till_here[i] = max(longest_increasing_subsequence_till_here[i],
                                                               1 + longest_increasing_subsequence_till_here[j]);
            }
        }
        longest_increasing_subsequence = max(longest_increasing_subsequence_till_here[i], longest_increasing_subsequence);
    }

    return longest_increasing_subsequence;

    }
};
