#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    #define all(v) (v).begin(), (v).end()

    vector <vector <int> > graph;
    vector <int> component;

    void dfs(int v, int c_no)
    {
        if(component[v] != 0)
            return;

        component[v] = c_no;

        for(int i = 0; i < graph[v].size(); i++)
        {
            int v_child = graph[v][i];

            if(component[v_child] == 0)
            {
                dfs(v_child, component[v]);
            }
        }
    }

    string smallestStringWithSwaps(string S, vector<vector<int> >& pairs)
    {
        graph.resize(S.size() + 1);

        for(int i = 0; i < pairs.size(); i++)
        {
            int first = pairs[i][0], second = pairs[i][1];

            graph[first].push_back(second);
            graph[second].push_back(first);
        }

        int no_of_components = 0;
        component.resize(S.size(), 0);

        for(int i = 0; i < S.size(); i++)
        {
            if(component[i] == 0)
            {
                no_of_components++;

                dfs(i, no_of_components);
            }
        }

        vector <vector <char> > component_chars(no_of_components + 1);
        for(int i = 0; i < S.size(); i++)
        {
            component_chars[component[i]].push_back(S[i]);
        }

        for(int i = 1; i <= no_of_components; i++)
        {
            sort(all(component_chars[i]));
        }

        vector <int> current_pointer(no_of_components + 1, 0);
        string answer;

        for(int i = 0; i < S.size(); i++)
        {
            int p = current_pointer[component[i]];

            char char_here = component_chars[component[i]][p];

            answer += char_here;

            current_pointer[component[i]]++;
        }

        return answer;
    }
};
