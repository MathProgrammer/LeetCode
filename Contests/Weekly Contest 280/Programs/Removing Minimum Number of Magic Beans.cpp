class Solution {
public:
    long long minimumRemoval(vector<int> &A) 
    {
        const int MAX_N = 1e5 + 1; 
        vector <long long> frequency(MAX_N, 0);
        for(int i = 0; i < A.size(); i++)
        {
            frequency[A[i]]++;
        }
        
        vector <long long> prefix_sum(MAX_N, 0);
        for(int i = 1; i < MAX_N; i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + frequency[i]*i;
        }
        
        vector <long long> suffix_sum(MAX_N + 1, 0), suffix_count(MAX_N + 1, 0);
        for(int i = MAX_N - 1; i >= 1; i--)
        {
            suffix_sum[i] = suffix_sum[i + 1] + frequency[i]*i;
            suffix_count[i] = suffix_count[i + 1] + frequency[i];
        }
        
        const long long oo = 1e18;
        long long answer = oo;
        for(int i = 1; i < MAX_N; i++)
        {
            answer = min(answer, prefix_sum[i - 1] + suffix_sum[i + 1] - i*suffix_count[i + 1]);
        }
        
        return answer;
    }
};
