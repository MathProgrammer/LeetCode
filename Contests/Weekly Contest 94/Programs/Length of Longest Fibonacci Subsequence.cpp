#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    int lenLongestFibSubseq(vector<int>& A)
    {
        map <int, int> index;
        for(int i = 0; i < A.size(); i++)
            index[A[i]] = i;

        int n = A.size();
        typedef vector <int> v_int;
        vector <v_int> max_sequence_ending_at(n + 1, v_int(n + 1, 0));

        int answer = 0;

        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                int third_last = A[i] - A[j];

                if(third_last < A[j] && index.find(third_last) != index.end())
                    max_sequence_ending_at[i][j] = 1 + max_sequence_ending_at[j][index[third_last]];
                else
                    max_sequence_ending_at[i][j] = 2;

                answer = max(answer, max_sequence_ending_at[i][j]);
            }
        }

        if(answer <= 2)
            answer = 0;

        return answer;
    }
};
