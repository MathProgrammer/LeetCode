#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int no_of_elements = nums1.size();
        vector <vector <int> > largest_answer_ending_with(no_of_elements, vector <int> (2, 0));

        const int A = 0, B = 1;
        int answer = 0;
        for(int i = 0; i < no_of_elements; i++)
        {
            largest_answer_ending_with[i][A] = largest_answer_ending_with[i][B] = 1;

            if(i > 0)
            {
                if(nums1[i] >= nums1[i - 1])
                {
                    largest_answer_ending_with[i][A] = max(largest_answer_ending_with[i][A], 1 + largest_answer_ending_with[i - 1][A]);
                }

                if(nums1[i] >= nums2[i - 1])
                {
                    largest_answer_ending_with[i][A] = max(largest_answer_ending_with[i][A], 1 + largest_answer_ending_with[i - 1][B]);
                }

                if(nums2[i] >= nums2[i - 1])
                {
                    largest_answer_ending_with[i][B] = max(largest_answer_ending_with[i][B], 1 + largest_answer_ending_with[i - 1][B]);
                }

                if(nums2[i] >= nums1[i - 1])
                {
                    largest_answer_ending_with[i][B] = max(largest_answer_ending_with[i][B], 1 + largest_answer_ending_with[i - 1][A]);
                }
            }

            int answer_here = max(largest_answer_ending_with[i][A], largest_answer_ending_with[i][B]);
            answer = max(answer, answer_here);
        }

        return answer;
    }
};
