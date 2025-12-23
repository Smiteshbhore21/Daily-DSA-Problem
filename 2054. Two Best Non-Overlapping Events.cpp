class Solution {
public:
    vector<vector<int>> memo;
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        memo.assign(n, vector<int>(3, -1));
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        vector<int> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = events[i][0];

        return solve(0, 0, events, starts);
    }

    int solve(int i, int taken, vector<vector<int>>& events,
              vector<int>& starts) {

        if (i >= events.size() || taken == 2)
            return 0;

        if (memo[i][taken] != -1)
            return memo[i][taken];

        int notTake = solve(i + 1, taken, events, starts);

        int nextStart = events[i][1] + 1;
        int nextIndex = lower_bound(starts.begin(), starts.end(), nextStart) -
                        starts.begin();
        int take = events[i][2] + solve(nextIndex, taken + 1, events, starts);

        return memo[i][taken] = max(take, notTake);
    }
};
