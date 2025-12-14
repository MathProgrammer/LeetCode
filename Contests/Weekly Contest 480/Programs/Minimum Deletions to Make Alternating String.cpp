#include <cstring> 
#include <vector> 

using namespace std; 

class Node
{
    private: 
    int longest_sequence[2][2];
    
    public: 
    Node()
    {
        memset(longest_sequence, 0, sizeof(longest_sequence));
    }
    
    Node(int n)
    {
        memset(longest_sequence, 0, sizeof(longest_sequence));
        longest_sequence[n][n] = 1;
    }

    Node(Node &L, Node &R)
    {
        memset(longest_sequence, 0, sizeof(longest_sequence));
        for(int beginning = 0; beginning < 2; beginning++)
        {
            for(int ending = 0; ending < 2; ending++)
            {
                longest_sequence[beginning][ending] = max(L.get_sequence(beginning,ending), R.get_sequence(beginning, ending));
                
                for(int L_ending = 0; L_ending < 2; L_ending++)
                {
                    int R_beginning = 1 - L_ending; 

                    if(L.get_sequence(beginning, L_ending) == 0 || 
                       R.get_sequence(R_beginning, ending) == 0)
                    {
                        continue;
                    }

                     int current_sequence = L.get_sequence(beginning, L_ending) + R.get_sequence(R_beginning, ending);
                    longest_sequence[beginning][ending] = max(longest_sequence[beginning][ending], current_sequence);
                }
            }
        }
    }

    int get_sequence(int start, int end)
    {
        return longest_sequence[start][end];
    }

    int get_longest_alternating_sequence()
    {
        int sequence = 0; 
        for(int beginning = 0; beginning < 2; beginning++)
        {
            for(int ending = 0; ending < 2; ending++)
            {
                sequence = max(sequence, longest_sequence[beginning][ending]);
            }
        }

        return sequence;
    }
};

class SegmentTree
{
    #define LEFT(n) (2*n)
    #define RIGHT(n) (2*n + 1)
    
    private:
    int no_of_elements;
    vector <Node> tree; 

    void update(int n, int left, int right, int point, int value)
    {
        if(point < left || right < point)
        {
            return;
        }

        if(left == right)
        {
            tree[n] = Node(value);
            return;
        }

        int mid = (left + right)/2; 
        update(LEFT(n), left, mid, point, value); 
        update(RIGHT(n), mid + 1, right, point, value);

        tree[n] = Node(tree[LEFT(n)], tree[RIGHT(n)]);
    }

    Node get_range_node(int n, int left, int right, int query_left, int query_right)
    {
        if(query_right < left || right < query_left)
        {
            return Node();
        }

        if(query_left <= left && right <= query_right)
        {
            return tree[n];
        }

        int mid = (left + right)/2; 
        Node left_range = get_range_node(LEFT(n), left, mid, query_left, query_right); 
        Node right_range = get_range_node(RIGHT(n), mid + 1, right, query_left, query_right);

        Node sum_range = Node(left_range, right_range);
        return sum_range;
    }

    public: 
    SegmentTree(int n)
    {
        no_of_elements = n;
        tree.resize(4*n);
    }

    void update(int point, int value)
    {
        update(1, 0, no_of_elements - 1, point, value);
    }

    int get_longest_alternating_sequence(int left, int right)
    {
        Node range = get_range_node(1, 0, no_of_elements - 1, left, right);
        return range.get_longest_alternating_sequence();
    }
};

class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) 
    {
        SegmentTree segmentTree(s.size()); 
        for(int i = 0; i < s.size(); i++)
        {
            s[i] = 'B' - s[i];
            segmentTree.update(i, s[i]);
        }

        int no_of_queries = queries.size();
        vector <int> answer;
        for(int q = 0; q < no_of_queries; q++)
        {
            int query_type = queries[q][0]; 
            const int FLIP = 1, GET_MIN_DELETIONS = 2;
            switch(query_type)
            {
                case FLIP :
                {
                    int index = queries[q][1];
                    s[index] = 1 - s[index];
                    segmentTree.update(index, s[index]);
                    break;
                }
                    
                case GET_MIN_DELETIONS : 
                {
                    int left = queries[q][1], right = queries[q][2];
                    int length = right - left + 1;
                    int longest_alternating_sequence = segmentTree.get_longest_alternating_sequence(left, right); 
                    int deletions = length - longest_alternating_sequence; 

                    answer.push_back(deletions);
                    break;
                }
            }
        }
        
        return answer;
    }
};