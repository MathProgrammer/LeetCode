class Solution {
public:
    int minPairSum(vector<int>&A) {
        sort(A.begin(), A.end());
        
        int answer = 0;
        for(int i = 0, j = A.size() - 1; i < j; i++, j--)
        {
            answer = max(answer, A[i] + A[j]);
        }
        
        return answer;
    }
};
