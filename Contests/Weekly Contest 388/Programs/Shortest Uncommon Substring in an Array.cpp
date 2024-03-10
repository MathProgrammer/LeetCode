#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    string get_substring(string &s, int left, int right)
    {
        string substring;
        for(int i = left; i <= right; i++)
        {
            substring += s[i];
        }

        return substring;
    }

    vector<string> shortestSubstrings(vector<string>& arr)
    {
        map <string, int> last_occurrence;
        for(int i = 0; i < arr.size(); i++)
        {
            for(int left = 0; left < arr[i].size(); left++)
            {
                for(int right = left; right < arr[i].size(); right++)
                {
                    string current_substring = get_substring(arr[i], left, right);
                    last_occurrence[current_substring] = i;
                    //cout << "Last Pccurence " << current_substring << " = " << i << "\n";
                }
            }
        }

        map <string, int> first_occurrence;
        for(int i = arr.size() - 1; i >= 0; i--)
        {
            for(int left = 0; left < arr[i].size(); left++)
            {
                for(int right = left; right < arr[i].size(); right++)
                {
                    string current_substring = get_substring(arr[i], left, right);
                    first_occurrence[current_substring] = i;
                    //cout << "First Pccurence " << current_substring << " = " << i << "\n";
                }
            }
        }

        vector <string> answer(arr.size());
        for(int i = 0; i < arr.size(); i++)
        {
            int answer_found = false;
            for(int length = 1; length <= arr[i].size() && !answer_found; length++)
            {
                for(int left = 0, right = left + length - 1; right < arr[i].size(); left++, right++)
                {
                    string current_substring = get_substring(arr[i], left, right);

                    if(first_occurrence[current_substring] == i && last_occurrence[current_substring] == i)
                    {
                        answer[i] =  (answer[i] == "" ? current_substring : min(answer[i], current_substring));
                        answer_found = true;
                    }
                }
            }
        }

        return answer;
    }
};
