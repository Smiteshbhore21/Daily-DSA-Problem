using ll = long long;
class Solution {
public:
    unordered_map<string, vector<pair<string, ll>>> adj;

    unordered_map<string, unordered_map<string, ll>> dijkstraMemo;

    vector<ll> dpMemo;

    string sourceStr, targetStr;

    set<int> validLengths;

    ll dijkstra(string& start, string& end) {
        if (dijkstraMemo[start].count(end))
            return dijkstraMemo[start][end];

        priority_queue<pair<ll, string>, vector<pair<ll, string>>,
                       greater<pair<ll, string>>>
            pq;

        unordered_map<string, ll> result;
        result[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            ll currCost = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if (node == end)
                break;

            for (auto& edge : adj[node]) {
                string adjNode = edge.first;
                ll edgeCost = edge.second;

                if (!result.count(adjNode) ||
                    currCost + edgeCost < result[adjNode]) {
                    result[adjNode] = currCost + edgeCost;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }

        return dijkstraMemo[start][end] =
                   result.count(end) ? result[end] : 1e10;
    }

    ll solve(int idx) {
        if (idx >= sourceStr.length())
            return 0;

        if (dpMemo[idx] != -1)
            return dpMemo[idx];

        ll minCost = 1e10;

        if (sourceStr[idx] == targetStr[idx])
            minCost = solve(idx + 1);

        for (const int& len : validLengths) {
            if (len + idx > sourceStr.length()) {
                break;
            }

            string srcSub = sourceStr.substr(idx, len);
            string tgtSub = targetStr.substr(idx, len);

            if (!adj.count(srcSub)) {
                continue;
            }

            ll minPathCost = dijkstra(srcSub, tgtSub);

            if (minPathCost == 1e10)
                continue;

            minCost = min(minCost, minPathCost + solve(idx + len));
        }

        return dpMemo[idx] = minCost;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        sourceStr = source;
        targetStr = target;

        dpMemo.assign(10001, -1);

        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
            validLengths.insert(original[i].size());
        }

        ll result = solve(0);

        return result == 1e10 ? -1 : result;
    }
};
