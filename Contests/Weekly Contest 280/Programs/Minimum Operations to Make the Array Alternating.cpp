class Solution {
public:
    
    int minimumOperations(vector<int> &A) 
    {
        const int MAX_N = 1e5 + 1;
        vector <int> odd_frequency(MAX_N, 0), even_frequency(MAX_N, 0);
        int total_even = 0, total_odd = 0;
        for(int i = 0; i < A.size(); i++)
        {
            switch(i%2)
            {
                case 0: even_frequency[A[i]]++; total_even++; break;
                case 1: odd_frequency[A[i]]++; total_odd++; break;
            }
        }
        
        int final_odd = 0, second_final_odd = 0, final_even = 0, second_final_even = 0;
        for(int i = MAX_N - 1; i >= 1 ; i--)
        {
            if(odd_frequency[i] >= odd_frequency[final_odd])
            {
                second_final_odd = final_odd; 
                final_odd = i;
            }
            else if(odd_frequency[i] > odd_frequency[second_final_odd])
            {
                second_final_odd = i;
            }
            
            if(even_frequency[i] >= even_frequency[final_even])
            {
                second_final_even = final_even;
                final_even = i;
            }
            else if(even_frequency[i] > even_frequency[second_final_even])
            {
                second_final_even = i;
            }
        }
        
        int answer = 0;
        
        if(final_odd != final_even)
        {
            answer = total_odd - odd_frequency[final_odd] + total_even - even_frequency[final_even];
        }
        else 
        {
            answer = min(total_odd - odd_frequency[final_odd] + total_even - even_frequency[second_final_even], 
                         total_odd - odd_frequency[second_final_odd] + total_even - even_frequency[final_even]);
        }
        
        return answer;
    }
};
