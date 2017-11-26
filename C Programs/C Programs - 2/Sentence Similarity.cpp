#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence_1, vector<string>& sentence_2, vector<pair<string, string>> pairs) {

        if(sentence_1.size() != sentence_2.size())
            return false;

        for(int i = 0; i < sentence_1.size(); i++)
        {
            string word_1 = sentence_1[i];
            string word_2 = sentence_2[i];

            int match = (word_1 == word_2);

            for(int j = 0; j < pairs.size(); j++)
            {
                if( (pairs[j].first == word_1 && pairs[j].second == word_2) ||
                    (pairs[j].first == word_2 && pairs[j].second == word_1) )
                    match = true;
            }

            if(match == false)
                return false;
        }

        return true;
    }
};
