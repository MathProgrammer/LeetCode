class FindSumPairs {
public:
    vector <int> A, B;
    map <int, int> frequency;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        A = nums1; 
        B = nums2;
        
        for(int i = 0; i < B.size(); i++)
        {
            frequency[B[i]]++;
        }
    }
    
    void add(int index, int value) 
    {
        frequency[B[index]]--;
        
        B[index] += value;
            
        frequency[B[index]]++;
    }
    
    int count(int sum) 
    {
        int pairs = 0;
        
        for(int i = 0; i < A.size(); i++)
        {
            pairs += frequency[sum - A[i]];
        }
        
        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
