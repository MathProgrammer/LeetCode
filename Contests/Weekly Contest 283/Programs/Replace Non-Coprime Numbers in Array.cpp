class Solution {
public:
    
    int lcm(int x, int y)
    {
        int g = __gcd(x, y);
        return (x*1LL*y)/g;
    }
    
    int all_coprime(vector <int> &A)
    {
        for(int i = 0; i + 1 < A.size(); i++)
        {
            if(__gcd(A[i], A[i + 1]) != 1)
            {
                return false;
            }
        }
        
        return true;
    }
    
    vector<int> replaceNonCoprimes(vector<int>& A) 
    {
       
        while(!all_coprime(A))
        {   
            vector <int> final_A;
            for(int i = 0, current = 0; i < A.size(); )
            {
                int current_element = A[i];
                for(current = i + 1; current < A.size(); current++)
                {
                    if(__gcd(A[current], current_element) == 1)
                    {
                        i = current;
                        break;
                    }

                    current_element = lcm(current_element, A[current]);
                }

                i = current;
                final_A.push_back(current_element);
                
            }
         
            A = final_A;
            final_A.clear();
            
            for(int i = A.size() - 1, current = A.size() - 1; i >= 0; )
            {
                int current_element = A[i];
                for(current = i - 1; current >= 0; current--)
                {
                    if(__gcd(A[current], current_element) == 1)
                    {
                        i = current;
                        break;
                    }

                    current_element = lcm(current_element, A[current]);
                }

                i = current;
                final_A.push_back(current_element);
                
            }
            
            reverse(final_A.begin(), final_A.end());
            A = final_A;
        }
        
        return A;
    }
};
