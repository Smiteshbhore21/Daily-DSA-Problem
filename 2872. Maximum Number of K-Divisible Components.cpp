using ll = long long;
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        if (n < 2)
            return 1;

        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        vector<ll> nodeVals(values.begin(), values.end());

        for (const vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }

        queue<int> qu;

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1)
                qu.push(i);
        }

        int componentCnt = 0;
        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            inDegree[curr]--;
            ll addVal = (nodeVals[curr] % k == 0) ? 0 : nodeVals[curr];
            if (addVal == 0)
                componentCnt++;
            for (const int& neighbor : adj[curr]) {
                if (inDegree[neighbor] > 0) {
                    inDegree[neighbor]--;
                    nodeVals[neighbor] += addVal;
                    if (inDegree[neighbor] == 1)
                        qu.push(neighbor);
                }
            }
        }
        return componentCnt;
    }
};
