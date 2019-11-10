#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    int is_set_bit(long long n, int bit)
    {
        return ( (n& (1LL << bit)) != 0);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        int no_of_words = words.size();

        const int NO_OF_ALPHABETS = 26;
        vector <int> frequency(NO_OF_ALPHABETS, 0);
        for(int i = 0; i < letters.size(); i++)
        {
            frequency[letters[i] - 'a']++;
        }

        vector <vector <int> > frequency_here(no_of_words, vector <int> (NO_OF_ALPHABETS, 0));
        for(int i = 0; i < no_of_words; i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                frequency_here[i][words[i][j] - 'a']++;
            }
        }

        int maximum_score = 0;
        for(int mask = 0; mask < (1LL << no_of_words); mask++)
        {
            vector <int> mask_frequency(NO_OF_ALPHABETS, 0);

            for(int bit = 0; bit < no_of_words; bit++)
            {
                if(!is_set_bit(mask, bit))
                {
                    continue;
                }

                for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
                {
                    mask_frequency[alpha] += frequency_here[bit][alpha];
                }
            }

            int score_here = 0;
            for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
            {
                if(mask_frequency[alpha] > frequency[alpha])
                {
                    score_here = 0;
                    break;
                }

                score_here += mask_frequency[alpha]*score[alpha];
            }

            maximum_score = max(maximum_score, score_here);
        }

        return maximum_score;
    }
};
