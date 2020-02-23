#include <vector>

using namespace std;

class Solution
{
    public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        vector <int> visited(n + 1, false);
        visited[0] = true;
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                return false;
            }
            
            if(leftChild[i] != -1)
            {
                if(visited[leftChild[i]])
                {
                    return false;
                }
                
                visited[leftChild[i]] = true;
            }
            
            if(rightChild[i] != -1)
            {
                if(visited[rightChild[i]])
                {
                    return false;
                }
                
                visited[rightChild[i]] = true;
            }
        }
        
        return true;
    }
};
