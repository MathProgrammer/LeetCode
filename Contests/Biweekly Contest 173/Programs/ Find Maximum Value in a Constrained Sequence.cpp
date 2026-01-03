#include <vector> 
using namespace std;

class Solution 
{
    public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) 
    {
        const int oo = 1e9;
        vector <int> restricted_value(n, oo); 
        for(int i = 0; i < restrictions.size(); i++)
        {
            int index = restrictions[i][0], value = restrictions[i][1]; 
            restricted_value[index] = value;
        }

        for(int i = n - 1; i >= 1; i--)
        {
            restricted_value[i - 1] = min(restricted_value[i - 1], restricted_value[i] + diff[i - 1]);
        }

        int answer = 0;
        vector <int> max_here(n); 
        for(int i = 0; i < n; i++)
        {
            max_here[i] = min(restricted_value[i], max_here[i - 1] + diff[i - 1]);
            answer = max(answer, max_here[i]);
        }

        return answer;
    }
};