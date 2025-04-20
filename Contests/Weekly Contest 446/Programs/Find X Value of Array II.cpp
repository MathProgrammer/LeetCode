#include <vector> 

using namespace std; 

#define LEFT(n) (2*n) 
#define RIGHT(n) (2*n + 1)

class Node
{
    private: 
    int mod, segment_mod;
    int prefix_frequency[5];

    public: 
    Node(int k) 
    {
        mod = k;
        segment_mod = 1;
        for(int m = 0; m < k; m++)
        {
            prefix_frequency[m] = 0;
        }
    }
    
    Node(int n, int k)
    {
        mod = k;
        segment_mod = n%k;
        for(int m = 0; m < k; m++)
        {
            prefix_frequency[m] = 0;
        }
        prefix_frequency[segment_mod] = 1; 
    }

    int get_prefix_frequency(int m)
    {
        return prefix_frequency[m];
    }

    void merge(Node left, Node right)
    {
        segment_mod = (left.segment_mod*right.segment_mod)%mod;
        
        for(int m = 0; m < mod; m++)
        {
            prefix_frequency[m] = left.prefix_frequency[m];
        }

        for(int suffix_m = 0; suffix_m < mod; suffix_m++)
        {
            int final_m = (left.segment_mod*suffix_m)%mod;
            prefix_frequency[final_m] += right.get_prefix_frequency(suffix_m);
        }
    }
};

class SegmentTree 
{
    private: 
    vector <Node> tree;
    int mod;
    
    public: 
    SegmentTree(int n, int k)
    {
        mod = k;
        tree.resize(4*n + 1, Node(mod));
    }

    Node getNode(int n)
    {
        return tree[n];
    }

    Node getNode(int n, int left, int right, int query_left, int query_right)
    {
        if(query_right < left || right < query_left)
        {
            return Node(mod);
        }
        
        if(query_left <= left && right <= query_right)
        {
            return tree[n];
        }

        int mid = (left + right)/2; 
        
        Node left_node = getNode(LEFT(n), left, mid, query_left, query_right);
        Node right_node = getNode(RIGHT(n), mid + 1, right, query_left, query_right);

        Node sum = Node(mod); 
        sum.merge(left_node, right_node); 

        return sum;
    }

    void update(int n, int left, int right, int position, int value)
    {
        if(position < left || right < position)
        {
            return;
        }

        if(left == right)
        {
            tree[n] = Node(value, mod);
            return;
        }

        int mid = (left + right)/2;
        update(LEFT(n), left, mid, position, value); 
        update(RIGHT(n), mid + 1, right, position, value);

        tree[n].merge(tree[LEFT(n)], tree[RIGHT(n)]);
    }
};

class Solution 
{
    public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) 
    {
        int no_of_elements = nums.size();
        SegmentTree segmentTree(no_of_elements, k);
        for(int i = 0; i < no_of_elements; i++)
        {
            segmentTree.update(1, 0, no_of_elements - 1, i, nums[i]);
        }

        vector <int> answer(queries.size());
        for(int q = 0; q < queries.size(); q++)
        {
            int index = queries[q][0], value = queries[q][1], start = queries[q][2], x = queries[q][3];

            nums[index] = value;
            segmentTree.update(1, 0, no_of_elements - 1, index, nums[index]);

            Node segment = segmentTree.getNode(1, 0, no_of_elements - 1, start, no_of_elements - 1);
            answer[q] = segment.get_prefix_frequency(x);
        }

        return answer;
    }
};