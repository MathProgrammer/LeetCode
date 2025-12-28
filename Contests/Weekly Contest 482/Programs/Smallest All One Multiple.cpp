class Solution {
public:
    int minAllOneMultiple(int k) 
    {
        if(k%2 == 0 || k%5 == 0)
        {
            return -1;
        }

        int answer_length = 1;
        int answer = 1; 
        while(answer%k != 0)
        {
            answer = answer*10 + 1;
            answer %= k;
            answer_length++;
        }

        return answer_length;
    }
};