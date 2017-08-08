#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(all(nums));

        int size = nums.size();

        //In case first two elements are negative, their product is positive. So there's no point in checking the three smallest numbers.
        //But, after choosing the biggest element in the array, check which 2-product is greater ... First 2 or last 2.
        int  product = nums[size-1]*max(nums[size - 2]*nums[size - 3], nums[0]*nums[1]);

        return product;

    }
};
