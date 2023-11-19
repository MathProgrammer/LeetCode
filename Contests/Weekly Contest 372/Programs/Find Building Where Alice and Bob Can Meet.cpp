#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

class Solution 
{
    public:
    
    void build(vector <int> &tree, vector <int> &A, int n, int left, int right)
    {
        if(left == right)
        {
            int value = A[right]; 
            tree[n] = value;
            return;
        }
        
        int mid = (left + right)/2;
        build(tree, A, LEFT(n), left, mid); 
        build(tree, A, RIGHT(n), mid + 1, right);
        
        tree[n] = max(tree[LEFT(n)], tree[RIGHT(n)]);
    }
    
    int get_max(vector <int> &tree, int n, int left, int right, int query_left, int query_right)
    {
        if(right < query_left || query_right < left)
        {
            return 0;
        }
        
        if(query_left <= left && right <= query_right)
        {
            return tree[n];
        }
        
        int mid = (left + right)/2;
        int left_max = get_max(tree, LEFT(n), left, mid, query_left, query_right);
        int right_max = get_max(tree, RIGHT(n), mid + 1, right, query_left, query_right);
        
        return max(left_max, right_max);
    }
    
    int find_first_greater(vector <int> &tree, int left, int right, int value)
    {
        int no_of_elements = right;
        if(get_max(tree, 1, 0, no_of_elements, left, right) <= value)
        {
            return -1;
        }
        
        //A[L] < V <= Max[R]
        while(right - left > 1)
        {
            int mid = (left + right)/2;
            
            if(get_max(tree, 1, 0, no_of_elements, left, mid) > value)
            {
                right = mid;
            }
            else 
            {
                left = mid;
            }
        }
        
        return right;
    }
    
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) 
    {
        int no_of_elements = heights.size();
        vector <int> max_tree(4*no_of_elements);
        build(max_tree, heights, 1, 0, no_of_elements - 1);
        
        int no_of_queries = queries.size(); 
        vector <int> answer(no_of_queries);
        for(int i = 0; i < no_of_queries; i++)
        {
            int left = queries[i][0], right = queries[i][1];
            if(right < left)
            {
                swap(left, right);
            }
            
            if(heights[left] < heights[right] || left == right)
            {
                answer[i] = right;
            }
            else 
            {
                answer[i] = find_first_greater(max_tree, right, no_of_elements - 1, heights[left]);
            }
        }
        
        return answer;
    }
};
