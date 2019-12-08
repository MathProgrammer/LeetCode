#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    long long sum_divided_by(vector <int> &A, int x)
    {
        long long sum = 0;
        for(int i = 0; i < A.size(); i++)
        {
            sum += (A[i]/x) + (A[i]%x != 0);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int left = 1, right = 1e9;

        if(sum_divided_by(nums, 1) <= threshold)
        {
            return 1;
        }

        //Left is always not possible, Right is always possible
        while(right - left > 1)
        {
            int mid = (left + right)/2;

            if(sum_divided_by(nums, mid) <= threshold)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        return right;
    }
};
