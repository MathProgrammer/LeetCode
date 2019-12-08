#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    vector<vector<int> > groupThePeople(vector<int>& groupSizes)
    {
        int no_of_people = groupSizes.size();
        vector < vector <int> > group_members_of_size(no_of_people + 1);

        for(int i = 0; i < no_of_people; i++)
        {
            group_members_of_size[groupSizes[i]].push_back(i);
        }

        vector <vector <int> > groups;

        for(int i = 1; i <= no_of_people; i++)
        {
            vector <int> current_group;

            for(int j = 0; j < group_members_of_size[i].size(); j++)
            {
                int current_person = group_members_of_size[i][j];

                if( (j + 1)%i == 0 ) //End of 1 Group
                {
                    current_group.push_back(current_person);

                    groups.push_back(current_group);

                    current_group.clear();

                    continue;
                }

                current_group.push_back(current_person);
            }
        }

        return groups;
    }
};

