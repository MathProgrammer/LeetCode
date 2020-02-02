#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        vector <pair <int, int> > strengths;
        for(int i = 0; i < mat.size(); i++)
        {
            int strength = 0;
            for(int j = 0; j < mat[i].size(); j++)
            {
                strength += (mat[i][j] == 1);
            }
            
            strengths.push_back(make_pair(strength, i));
        }
        
        sort(strengths.begin(), strengths.end());
        
        vector <int> answer;
        for(int i = 0; i < k; i++)
        {
            answer.push_back(strengths[i].second);
        }
        
        return answer;
    }
};
