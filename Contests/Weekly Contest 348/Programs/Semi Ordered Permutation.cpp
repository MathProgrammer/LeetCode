class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        vector <int> index(nums.size() + 1); 
        for(int i = 0; i < nums.size(); i++)
        {
            index[nums[i]] = i;
        }
        
        int n = nums.size();
        int moves = (index[1] - 0) + (n - 1 - index[n]);
        if(index[n] < index[1])
        {
            moves--;
        }
        
        return moves;
    }
};
