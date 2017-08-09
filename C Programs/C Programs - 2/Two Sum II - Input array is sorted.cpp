#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector <int> solution_pair;
        int i = 0, j = numbers.size() - 1;
        while(i < j)
        {
            if(numbers[i] + numbers[j] == target)
            {
                solution_pair.push_back(i + 1);
                solution_pair.push_back(j + 1);
                break;
            }
            else if(numbers[i] + numbers[j] < target)
            {
                i++;
            }
            else if(numbers[i] + numbers[j] > target)
            {
                j--;
            }

        }

        return solution_pair;
    }
};
