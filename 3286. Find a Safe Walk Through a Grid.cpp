class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> que;
        vector<vector<int>> best(m, vector<int>(n, -1));

        if (grid[0][0] == 1)
            health--;

        if (health <= 0)
            return false;

        que.push({{0, 0}, health});
        best[0][0] = health;

        while (!que.empty()) {
            int curr_i = que.front().first.first;
            int curr_j = que.front().first.second;
            int curr_health = que.front().second;
            que.pop();

            if (curr_i == m - 1 && curr_j == n - 1 && curr_health > 0)
                return true;

            for (vector<int>& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                    continue;

                int newHealth = curr_health;

                if (grid[new_i][new_j] == 1)
                    newHealth--;

                if (newHealth <= 0)
                    continue;

                if (newHealth > best[new_i][new_j]) {
                    best[new_i][new_j] = newHealth;
                    que.push({{new_i, new_j}, newHealth});
                }
            }
        }
        return false;
    }
};
