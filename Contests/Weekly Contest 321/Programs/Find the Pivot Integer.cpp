class Solution {
public:
    int pivotInteger(int n) {
        int pivot = -1; 
        
        for(int x = 1; x <= n; x++)
        {
            if(2*x*x == n*(n + 1))
            {
                pivot = x;
                break;
            }
        }
        
        return pivot;
    }
};
