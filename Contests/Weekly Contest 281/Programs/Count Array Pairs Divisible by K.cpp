class Solution {
public:
    long long choose_2(long long n)
    {
        return n*(n - 1)/2;
    }
    
    void factorise(vector <int> &F, vector <int> &E, int n)
    {
        for(int i = 2; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                int exponent = 0;
                
                while(n%i == 0)
                {
                    n /= i;
                    exponent++;
                } 
                
                F.push_back(i);
                E.push_back(exponent);
            }
        }
        
        if(n > 1)
        {
            F.push_back(n);
            E.push_back(1);
        }
    }
    
    int get_complement(int n, vector <int> &F, vector <int> &E)
    {
        int complement = 1;
        for(int i = 0; i < F.size(); i++)
        {
            int f = F[i];
            
            int exponent_n = 0;
            while(n%f == 0)
            {
                n /= f;
                exponent_n++;
            }
            
            while(exponent_n < E[i])
            {
                complement *= f; 
                exponent_n++;
            }
            
        }
        
        return complement;
    }
    
    long long coutPairs(vector<int>& A, int k) 
    {
        vector <int> factors, exponent; 
        factorise(factors, exponent, k);
        
        vector <long long> frequency(k, 0);
        for(int i = 0; i < A.size(); i++)
        {
            frequency[A[i]%k]++;
        }
        
        long long answer = 0;
        for(int m = 0; m < k; m++)
        {
            if(m == 0)
            {
                long long non_zero = A.size() - frequency[m];
                answer += choose_2(frequency[m]) + frequency[m]*non_zero;
                continue;
            }
            
            int complement = get_complement(m, factors, exponent);
            for(int i = 1; i*complement < k; i++)
            {
                int complement_multiple = i*complement;   
                if(complement_multiple > m)
                {
                    answer += frequency[m]*frequency[complement_multiple]; 
                }
                else if(i*complement == m)
                {
                     answer += choose_2(frequency[complement_multiple]);
                }
            }
        }
        
        return answer;
    }
};
