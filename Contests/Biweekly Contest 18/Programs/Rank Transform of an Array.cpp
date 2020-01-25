#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution
{
    public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        set <int> distinct;
        for(int i = 0; i < arr.size(); i++)
        {
            distinct.insert(arr[i]);
        }
        
        map <int, int> rank;
        int latest_rank = 1;
        
        for(auto it = distinct.begin(); it != distinct.end(); it++)
        {
            rank[*it] = latest_rank++;
        }
        
        for(int i = 0; i < arr.size(); i++)
        {
            arr[i] = rank[arr[i]];
        }
        
        return arr;
    }
};
