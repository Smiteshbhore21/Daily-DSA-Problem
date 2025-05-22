class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        priority_queue<int> avail_queries;
        priority_queue<int, vector<int>, greater<int>> used_queries;
        sort(begin(queries), end(queries));
        int query_pos = 0, applied_count = 0;
        for (int i = 0; i < n; i++) {
            while (query_pos < queries.size() && queries[query_pos][0] == i) {
                avail_queries.push(queries[query_pos][1]);
                query_pos++;
            }
            nums[i] -= used_queries.size();
            while (nums[i] > 0 and !avail_queries.empty() and
                   avail_queries.top() >= i) {
                used_queries.push(avail_queries.top());
                avail_queries.pop();
                nums[i]--;
                applied_count++;
            }
            if (nums[i] > 0)
                return -1;
            while (!used_queries.empty() and used_queries.top() == i) {
                used_queries.pop();
            }
        }
        return queries.size() - applied_count;
    }
};
