#include <vector> 
#include <iostream>

using namespace std; 

class Node
{
    private: 
    int first, last, length;
    long long increasing, prefix_increasing, suffix_increasing;
    
    public: 
    Node()
    {
        length = 0; 
        first = last = 0;

        prefix_increasing = suffix_increasing = increasing = 0;
    }
    
    Node(int n)
    {
        length = 1;
        first = last = n; 

        prefix_increasing = suffix_increasing = increasing = 1;
    }

    Node(Node left, Node right)
    {
        length = left.length + right.length;
        first = left.first, last = right.last; 

        prefix_increasing = left.prefix_increasing + 
            (left.prefix_increasing == left.length && left.last <= right.first 
             || left.last == 0 ? 
                right.prefix_increasing : 0);

        suffix_increasing = right.suffix_increasing + 
            (right.suffix_increasing == right.length && left.last <= right.first 
             || right.first == 0 ? 
                left.suffix_increasing : 0);
        
        long long new_increasing = (left.last <= right.first ? left.suffix_increasing*right.prefix_increasing : 0);

        increasing = left.increasing + right.increasing + new_increasing; 
    }

    long long get_stable_subarray_count()
    {
        return increasing;
    }

    void display()
    {
        cout << "Increasing = " << increasing << " Prefix increasing = " << prefix_increasing 
        << " Suffix increasing = " << suffix_increasing << "\n";
    }
};

class SegmentTree 
{
    #define LEFT(n) (2*n)
    #define RIGHT(n) (2*n + 1)
    
    private:
    int no_of_elements;
    vector <Node> tree; 

    void update(int n, int left, int right, int position, int value)
    {
        if(right < position || position < left)
        {
            return;
        }

        if(left == right)
        {
            tree[n] = Node(value);
            return;
        }

        int mid = (left + right)/2; 
        update(LEFT(n), left, mid, position, value); 
        update(RIGHT(n), mid + 1, right, position, value);  
        tree[n] = Node(tree[LEFT(n)], tree[RIGHT(n)]);
    }

    Node get(int n, int left, int right, int query_left, int query_right)
    {
        if(right < query_left || query_right < left)
        {
            return Node();
        }

        if(query_left <= left && right <= query_right)
        {
            return tree[n];
        }

        int mid = (left + right)/2; 
        Node left_answer = get(LEFT(n), left, mid, query_left, query_right); 
        Node right_answer = get(RIGHT(n), mid + 1, right, query_left, query_right); 
        Node answer = Node(left_answer, right_answer);

        return answer;
    }
    
    public: 
    SegmentTree(int n)
    {
        no_of_elements = n;
        tree.resize(4*no_of_elements);
    }

    void insert(int position, int value)
    {
        update(1, 0, no_of_elements - 1, position, value);
    }

    Node get(int left, int right)
    {
        return get(1, 0, no_of_elements - 1, left, right);
    }
};

    class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) 
    {
        SegmentTree segment_tree(nums.size()); 
        for(int i = 0; i < nums.size(); i++)
        {
            segment_tree.insert(i, nums[i]);
        }

        vector <long long> answer(queries.size());
        for(int q = 0; q < queries.size(); q++)
        {
            int left = queries[q][0], right = queries[q][1];
            Node answer_node = segment_tree.get(left, right);
            answer[q] = answer_node.get_stable_subarray_count();
        }

        return answer;
    }
};