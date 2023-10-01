#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& A) {
        int no_of_elements = A.size();
        vector <int> prefix_max(no_of_elements);
        prefix_max[0] = A[0];
        for(int i = 1; i < no_of_elements; i++)
        {
            prefix_max[i] = max(prefix_max[i - 1], A[i]);
        }

        vector <int> suffix_max(no_of_elements + 1);
        for(int i = no_of_elements - 1; i >= 0; i--)
        {
            suffix_max[i] = max(suffix_max[i + 1], A[i]);
        }

        long long answer = 0;
        for(int j = 1; j <= no_of_elements - 2; j++)
        {
            long long best_answer_with_this_j = (prefix_max[j - 1] - A[j])*1LL*suffix_max[j + 1];
            answer = max(answer, best_answer_with_this_j);
        }

        return answer;
    }
};
