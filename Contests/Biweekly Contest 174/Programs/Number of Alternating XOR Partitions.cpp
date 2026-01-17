#include <vector> 
#include <map>

using namespace std; 

class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) 
    {
        const int MOD = 1e9 + 7;
        vector <long long> answer_1(nums.size()), answer_2(nums.size());
        map <int, long long> good_endings_1, good_endings_2;
        int prefix_xor = 0;
        good_endings_2[prefix_xor] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            prefix_xor ^= nums[i];
            
            int segment_1_xor = prefix_xor^target1; 
            int good_endings_1_here = good_endings_2[segment_1_xor];

            int segment_2_xor = prefix_xor^target2; 
            int good_endings_2_here = good_endings_1[segment_2_xor];

            good_endings_1[prefix_xor] += good_endings_1_here;
            good_endings_1[prefix_xor] %= MOD;
            answer_1[i] = good_endings_1_here;
            
            good_endings_2[prefix_xor] += good_endings_2_here;
            good_endings_2[prefix_xor] %= MOD;
            answer_2[i] = good_endings_2_here;
        }

        long long answer = answer_1.back() + answer_2.back();
        answer %= MOD;
        return answer;
    }
};