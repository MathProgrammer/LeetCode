class Solution 
{
    public:
    int sumOfFlooredPairs(vector<int> &A) 
    {
        const long long MAX_N = 1e5, MOD = 1e9 + 7;
        vector <int> frequency(2*MAX_N + 5, 0);
        for(int i = 0; i < A.size(); i++)
        {
            frequency[A[i]]++;
        }
        
        vector <int> frequency_sum(2*MAX_N + 5, 0);
        for(int i = 1; i <= MAX_N; i++)
        {
            frequency_sum[i] = frequency_sum[i - 1] + frequency[i];
        }
        
        long long sum = 0;
        for(int i = 1; i <= MAX_N; i++)
        {
            if(frequency[i] == 0)
            {
                continue;
            }
            
            for(long long m = 1; m*i <= MAX_N; m++)
            {   //cout << "M = " << m << " i = " << i << "\n";
                int left = m*i, right = min(MAX_N, (m + 1)*i - 1); 
                
                int segment_contribution = frequency_sum[right] - frequency_sum[left - 1];
                
                segment_contribution = (segment_contribution*frequency[i])%MOD;
                
                segment_contribution = (segment_contribution*m)%MOD;
                
                sum = (sum + segment_contribution)%MOD;
            }
        }
        
        return sum;
    }
};
