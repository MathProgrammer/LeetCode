#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    const int NOT_POSSIBLE = -1;

    int min_steps(vector <int> &A, vector <int> &B)
    {
        int steps = 0;
        for(int i = 0; i + 1 < A.size(); i++)
        {
            if(A[i] <= A.back() && B[i] <= B.back())
            {
                continue;
            }
            else if(A[i] <= B.back() && B[i] <= A.back())
            {
                steps++;
            }
            else
            {
                steps = NOT_POSSIBLE;
                break;
            }
        }

        return steps;
    }

    int minOperations(vector<int>& nums1, vector<int>& nums2)
    {
        int operations = min_steps(nums1, nums2);

        swap(nums1.back(), nums2.back());
        int operations_with_swap = min_steps(nums1, nums2);
        if(operations_with_swap != -1)
        {
            operations_with_swap++;
        }

        int answer;
        if(operations == NOT_POSSIBLE && operations_with_swap == NOT_POSSIBLE)
        {
            answer = NOT_POSSIBLE;
        }
        else if(operations == NOT_POSSIBLE || operations_with_swap == NOT_POSSIBLE)
        {
            answer = (operations == NOT_POSSIBLE ? operations_with_swap : operations);
        }
        else
        {
            answer = min(operations, operations_with_swap);
        }

        return answer;
    }
};
