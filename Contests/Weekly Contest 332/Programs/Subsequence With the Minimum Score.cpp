class Solution {
public:
    
    //A is ascending/non-decreasing
    int binary_search_first_greater(vector <int> &A, int left, int right, int value)
    {
        //cout << "Binary searching first value greater than " << value << " in [" << left << "," << right << "]\n";
        if(value < A[left])
        {
            return left;
        }
        
        if(A[right] <= value)
        {
            return right + 1;
        }
        
        //A[L] <= V < A[R]
        while(right - left > 1)
        {
            int mid = (left + right)/2;
            
            if(A[mid] <= value)
            {
                left = mid;
            }
            else if(value < A[mid])
            {
                right = mid;
            }
        }
        
        return right;
    }
    
    //A is ascending/non-decreasing
    int binary_search_last_smaller(vector <int> &A, int left, int right, int value)
    {
       // cout << "Binary searching first value smaller than " << value << " in [" << left << "," << right << "]\n";
        if(value <= A[left])
        {
            return left - 1;
        }
        
        if(A[right] < value)
        {
            return right;
        }
        
        //A[L] < V <= A[R]
        while(right - left > 1)
        {
            int mid = (left + right)/2;
            
            if(A[mid] < value)
            {
                left = mid;
            }
            else if(value <= A[mid])
            {
                right = mid;
            }
        }
        
        return left;
    }
    
    int minimumScore(string S, string T) {
        vector <int> earliest_end_for_prefix(T.size());
        for(int i = 0, j = 0; j < T.size(); j++)
        {
            while(i < S.size() && S[i] != T[j])
            {
                i++;
            }
            
            earliest_end_for_prefix[j] = i;
            i++;
            //cout << "Earliest prefix " << j << " = " << earliest_end_for_prefix[j] << "\n";
        }
        
        vector <int> latest_beginning_for_suffix(T.size());
        for(int i = S.size() - 1, j = T.size() - 1; j >= 0; j--)
        {
            while(i >= 0 && S[i] != T[j])
            {
                i--;
            }
            
            latest_beginning_for_suffix[j] = i;
            i--;
            //cout << "Latest suffix " << j << " = " << latest_beginning_for_suffix[j] << "\n";
        }
        
        int best_score = T.size();
        
        if(earliest_end_for_prefix[T.size() - 1] < S.size())
        {
            best_score = 0;
        }
        
        for(int first_removed = 1; first_removed < T.size(); first_removed++)
        {
            int left = first_removed, right;
            if(left == T.size() - 1)
            {
                right = left; 
            }
            else 
            {
                right = binary_search_first_greater(latest_beginning_for_suffix, first_removed + 1, T.size() - 1, earliest_end_for_prefix[left - 1]) - 1;
            }
            
            //cout << "L = " << left << " R = " << right << "\n";
            
            if(earliest_end_for_prefix[left - 1] < S.size() && 
               right + 1 < T.size() && earliest_end_for_prefix[left - 1] < latest_beginning_for_suffix[right + 1])
            {
                best_score = min(best_score, right - left + 1);
            }
            
            if(earliest_end_for_prefix[left - 1] < S.size())
            {
                right = T.size() - 1;
                best_score = min(best_score, right - left + 1);
            }
        }
        
        for(int last_removed = T.size() - 2; last_removed >= 0; last_removed--)
        {
            int left, right = last_removed;
            if(right == 0)
            {
                left = right;
            }
            else 
            {
                left = binary_search_last_smaller(earliest_end_for_prefix, 0, last_removed - 1, latest_beginning_for_suffix[right + 1]) + 1;
            }
            
            //cout << "L = " << left << " R = " << right << "\n";
            
            if(latest_beginning_for_suffix[right + 1] >= 0 && 
               left - 1 >= 0 && earliest_end_for_prefix[left - 1] < latest_beginning_for_suffix[right + 1])
            {
                best_score = min(best_score, right - left + 1);
            }
            
            if(latest_beginning_for_suffix[right + 1] >= 0)
            {
                left = 0;
                best_score = min(best_score, right - left + 1);
            }
        }
        
        return best_score;
    }
};
