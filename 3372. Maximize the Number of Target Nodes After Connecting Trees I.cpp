//DFS -->
class Solution {
public:
    vector<int> findCount(vector<vector<int>>& edges, int d) {
        int N = edges.size() + 1;
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            result[i] = dfs(i, adj, d, -1);
        }
        return result;
    }

    int dfs(int curr, unordered_map<int, vector<int>>& adj, int d,
            int currNodeParent) {
        if (d < 0)
            return 0;
        int count = 1;
        for (int& ngbr : adj[curr]) {
            if (ngbr != currNodeParent) {
                count += dfs(ngbr, adj, d - 1, curr);
            }
        }
        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int N = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k),
                    result2 = findCount(edges2, k - 1);

        int maxTargetCount = *max_element(result2.begin(), result2.end());
        for (int i = 0; i < result1.size(); i++) {
            result1[i] += maxTargetCount;
        }
        return result1;
    }
};

//BFS -->
// class Solution {
// public:
//     vector<int> findCount(vector<vector<int>>& edges, int d) {
//         int N = edges.size() + 1;
//         unordered_map<int, vector<int>> adj;
//         for (vector<int>& edge : edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }

//         vector<int> result(N);
//         for (int i = 0; i < N; i++) {
//             result[i] = bsf(i, adj, d, N);
//         }
//         return result;
//     }

//     int bsf(int curr, unordered_map<int, vector<int>>& adj, int d, int N) {
//         queue<pair<int, int>> que;
//         que.push({curr, 0});
//         vector<bool> visited(N, false);
//         visited[curr] = true;
//         int count = 0;
//         while (!que.empty()) {
//             int currNode = que.front().first, dist = que.front().second;
//             que.pop();
//             if (dist > d) {
//                 continue;
//             }
//             count++;
//             for (auto& ngbr : adj[currNode]) {
//                 if (!visited[ngbr]) {
//                     visited[ngbr] = true;
//                     que.push({ngbr, dist + 1});
//                 }
//             }
//         }
//         return count;
//     }

//     vector<int> maxTargetNodes(vector<vector<int>>& edges1,
//                                vector<vector<int>>& edges2, int k) {
//         int N = edges1.size() + 1;

//         vector<int> result1 = findCount(edges1, k),
//                     result2 = findCount(edges2, k - 1);

//         int maxTargetCount = *max_element(result2.begin(), result2.end());
//         for (int i = 0; i < result1.size(); i++) {
//             result1[i] += maxTargetCount;
//         }
//         return result1;
//     }
// };
