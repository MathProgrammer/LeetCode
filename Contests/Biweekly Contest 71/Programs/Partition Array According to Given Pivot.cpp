class Solution {
public:
    
    void append(vector <int> &target, vector <int> &source)
    {
        for(int x : source)
        {
            target.push_back(x);
        }
    }
    
    vector<int> pivotArray(vector<int> &A, int pivot) 
    {    
        vector <int> lesser, greater, equal; 
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] < pivot)
            {
                lesser.push_back(A[i]);
            }
            else if(A[i] == pivot)
            {
                equal.push_back(A[i]);
            }
            else if(A[i] > pivot)
            {
                greater.push_back(A[i]);
            }
        }
        
        vector <int> answer;
        append(answer, lesser);
        append(answer, equal);
        append(answer, greater);
        
        return answer;
    }
};
