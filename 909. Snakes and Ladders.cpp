class Solution {
public:
    pair<int, int> getCoord(int pos, int n) {
        int rowTop = (pos - 1) / n;
        int rowBottom = (n - 1) - rowTop;
        int col = (pos - 1) % n;
        if ((n % 2 == 1 && rowBottom % 2 == 1) ||
            (n % 2 == 0 && rowBottom % 2 == 0))
            col = (n - 1) - col;
        return {rowBottom, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        return bfs(board, n);
    }

    int bfs(vector<vector<int>>& board, int& n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<int> q;
        q.push(1);
        visited[n - 1][0] = true;
        int steps = 0;
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                int x = q.front();
                q.pop();
                if (x == n * n)
                    return steps;
                for (int i = 1; i <= 6; i++) {
                    int val = x + i;

                    if (val > n * n)
                        break;

                    pair<int, int> coord = getCoord(val, n);
                    int r = coord.first, c = coord.second;
                    if (visited[r][c] == true)
                        continue;
                    visited[r][c] = true;
                    if (board[r][c] == -1) {
                        q.push(val);
                    } else {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
