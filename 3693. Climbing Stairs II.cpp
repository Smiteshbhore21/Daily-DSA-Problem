class Solution {
public:
    vector<int> memo;
    int climbStairs(int n, vector<int>& costs) {
        memo.assign(n + 1, -1);
        return solve(0, n, costs);
    }

    int solve(int i, int n, vector<int>& costs) {
        if (i == n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int cost = INT_MAX;

        for (int jump = 1; jump <= 3; jump++) {
            int j = i + jump;

            if (j <= n) {
                int currCost = solve(j, n, costs) + costs[j - 1] + jump * jump;

                cost = min(cost, currCost);
            }
        }

        return memo[i] = cost;
    }
};
