class Solution {
public:
    long long minimumDifference(vector<int> &A) 
    {
        priority_queue <long long, vector <long long>, greater <long long>> PQ; 
        int n = A.size()/3;
        
        long long sum = 0;
        vector <long long> maximum_sum(A.size() + 1, 0);
        for(int i = A.size() - 1; i >= 0; i--)
        {
            if(PQ.size() < n)
            {
                PQ.push(A[i]);
                sum += A[i];
            }
            else if(PQ.size() == n)
            {
                if(PQ.top() < A[i])
                {
                    sum -= PQ.top(); 
                    PQ.pop(); 
                    PQ.push(A[i]);
                    sum += A[i];
                }
            }
            
            maximum_sum[i] = sum;
        }
        
        const long long oo = 1e14; 
        sum = 0;
        vector <long long> minimum_sum(A.size() + 1, oo);
        priority_queue <long long > min_PQ;
        for(int i = 0; i < A.size(); i++)
        {
            if(min_PQ.size() < n)
            {
                min_PQ.push(A[i]);
                sum += A[i]; 
            }
            else if(min_PQ.size() == n)
            {
                if(min_PQ.top() > A[i])
                {
                    sum -= min_PQ.top(); 
                    min_PQ.pop(); 
                    min_PQ.push(A[i]);
                    sum += A[i];
                }
            }
            
            minimum_sum[i] = sum;
        }
        
        long long answer = oo;
        
        for(int i = n - 1; i < 2*n; i++)
        {
            answer = min(answer, minimum_sum[i] - maximum_sum[i + 1]);
        }
        
        return answer;
    }
};
