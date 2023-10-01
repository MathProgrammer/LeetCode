#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int get_whole_arrays_with_sum(long long suffix_sum, long long array_sum, int target)
    {
        int left = 0, right = target;
        while(right - left > 1)
        {
            int mid = (left + right)/2;

            if(suffix_sum + mid*array_sum <= target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }

    int minSizeSubarray(vector<int>& A, int target) {
        int no_of_elements = A.size();

        map <long long, int> prefix_sum_index;
        vector <long long> prefix(no_of_elements);
        prefix_sum_index[0] = 0;
        for(int i = 0; i < no_of_elements; i++)
        {
            prefix[i] = A[i] + (i > 0 ? prefix[i - 1] : 0);
            prefix_sum_index[prefix[i]] = i + 1;
        }

        vector <long long> suffix(no_of_elements + 1);
        for(int i = no_of_elements - 1; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + A[i];
        }

        int answer = target + 1;
        for(int i = 0; i < no_of_elements; i++)
        {
            int prefix_sum_required = prefix[i] - target;
            if(prefix_sum_index.count(prefix_sum_required) == 1)
            {
                int current_answer_length = i - prefix_sum_index[prefix_sum_required] + 1;
                answer = min(answer, current_answer_length);
            }
        }

        long long sum = 0;
        for(int i = 0; i < no_of_elements; i++)
        {
            sum += A[i];
        }

        for(int i = no_of_elements; i >= 1; i--)
        {
            long long suffix_sum = suffix[i];
            if(suffix_sum > target)
            {
                continue;
            }

            int no_of_whole_arrays = get_whole_arrays_with_sum(suffix_sum, sum, target);
            long long remaining_sum = target - suffix_sum - no_of_whole_arrays*sum;

            if(prefix_sum_index.count(remaining_sum) == 1)
            {
                int prefix = prefix_sum_index[remaining_sum], suffix = no_of_elements - i;
                int current_answer_length = suffix + (no_of_whole_arrays*no_of_elements) + prefix;
                answer = min(answer, current_answer_length);
            }

        }

        if(answer == target + 1)
        {
            answer = -1;
        }

        return answer;
    }
};
