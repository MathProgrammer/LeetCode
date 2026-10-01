#include <vector> 

using namespace std; 
class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) 
    {
        int answer = 2; 
        int row_difference = abs(source[0] - target[0]);
        int column_difference = abs(source[1] - target[1]);
        if(row_difference == column_difference || row_difference == 0 || column_difference == 0)
        {
            answer = 1;
        }

        if(row_difference == 0 && column_difference == 0)
        {
            answer = 0;
        }

        return answer;
    }
};