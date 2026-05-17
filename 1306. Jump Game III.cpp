class Solution {
public:
    int n;
    vector<int> memo;
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<int> visited(n, false);
        memo.assign(n + 1, -1);
        return solve(start, arr, visited);
    }

    bool solve(int i, vector<int>& arr, vector<int>& visited) {
        if (i >= n || i < 0)
            return memo[i] = 0;
        if (arr[i] == 0)
            return memo[i] = 1;

        visited[i] = true;

        if (memo[i] != -1)
            return memo[i];

        if (i + arr[i] < n && !visited[i + arr[i]] &&
            solve(i + arr[i], arr, visited)) {
            return memo[i] = 1;
        }

        if (i - arr[i] >= 0 && !visited[i - arr[i]] &&
            solve(i - arr[i], arr, visited)) {
            return memo[i] = 1;
        }

        return memo[i] = 0;
    }
};
