class Solution {
public:
    
    int LIS(vector <int> &A)
    {
        multiset <int> lis; 
        
        for(int i = 0; i < A.size(); i++)
        {
            auto index = lis.upper_bound(A[i]);
            
            if(index != lis.end())
            {
                lis.erase(index);
            }
            
            lis.insert(A[i]);
        }
        
        return lis.size();
    }
    
    int kIncreasing(vector<int>& A, int k) {
        vector <vector <int> > sequence(k); 
        
        for(int i = 0; i < A.size(); i++)
        {
            sequence[i%k].push_back(A[i]);
        }
        
        int changes = 0; 
        for(int i = 0; i < k; i++)
        {
            changes += sequence[i].size() - LIS(sequence[i]);
        }
        
        return changes;
    }
};
