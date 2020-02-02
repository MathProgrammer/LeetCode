#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Solution
{
    public:
    int minSetSize(vector<int>& arr)
    {
        map <int, int> frequency;
        for(int i = 0; i < arr.size(); i++)
        {
            frequency[arr[i]]++;
        }
        
        set <pair <int, int> > S;
        for(auto it = frequency.begin(); it != frequency.end(); it++)
        {
            S.insert(make_pair(it->second, it->first));
        }
        
        int taken_frequency = 0, taken_elements = 0;
        for(auto it = S.rbegin(); it != S.rend(); it++)
        {
            taken_frequency += (*it).first;
            
            taken_elements++;
            
            if(taken_frequency >= arr.size()/2)
            {
                return taken_elements;
            }
        }
        
        return 0;
    }
};
