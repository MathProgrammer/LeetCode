class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector <pair <int, int> > k_score(score.size());
        for(int i = 0; i < score.size(); i++)
        {
            k_score[i] = (make_pair(score[i][k], i));
        }
        sort(k_score.begin(), k_score.end());
        
        vector <vector <int> > answer(score.size());
        for(int i = 0, j = score.size() - 1; i < score.size(); i++, j--)
        {
            int current_student = k_score[i].second;
            answer[j] = score[current_student];
        }
        
        return answer;
    }
};
