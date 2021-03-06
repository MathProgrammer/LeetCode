class Solution {
public:
    
    void rotate(vector < vector <int> > &M)
    {
        int n = M.size(); 
        vector < vector <int> > rotated(n, vector <int> (n));
        for(int i = 0, rotated_column = n - 1; i < n; i++, rotated_column--)
        {
            for(int p = 0; p < n; p++)
            {
                rotated[p][rotated_column] = M[i][p];
            }
        }
        M = rotated;
    }
     
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int n = mat.size(); 
        for(int r = 1; r <= 4; r++)
        {
            rotate(mat);
            
            if(mat == target)
            {
                return true;
            }
        }
        
        return false;
    }
};
