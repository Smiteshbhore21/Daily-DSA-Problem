// dijkstra --> O(n * (V + E) * log(V)) -->
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<int, char>>> adjList;
        for (int i = 0; i < original.size(); i++) {
            adjList[original[i]].push_back({cost[i], changed[i]});
        }

        vector<vector<long long>> costMatrix(26,
                                             vector<long long>(26, INT_MAX));

        for (int i = 0; i < source.length(); i++) {
            char ch = source[i];
            dijkstra(ch, adjList, costMatrix);
        }

        long long result = 0;
        int n = source.length();
        for (int i = 0; i < n; i++) {
            if (source[i] == target[i]) {
                continue;
            }
            if (costMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }
            result += costMatrix[source[i] - 'a'][target[i] - 'a'];
        }
        return result;
    }

    void dijkstra(char& source,
                  unordered_map<char, vector<pair<int, char>>>& adjList,
                  vector<vector<long long>>& costMatrix) {

        priority_queue<pair<long long, char>, vector<pair<long long, char>>,
                       greater<pair<long long, char>>>
            pq;

        pq.push({0, source});

        while (!pq.empty()) {
            int dist = pq.top().first;
            char adjNode = pq.top().second;
            pq.pop();

            for (auto& it : adjList[adjNode]) {
                char neighb = it.second;
                int cost = it.first;

                if (costMatrix[source - 'a'][neighb - 'a'] > dist + cost) {
                    costMatrix[source - 'a'][neighb - 'a'] = dist + cost;
                    pq.push({dist + cost, neighb});
                }
            }
        }
    }
};

// floydWarshall --> O(n + m) -->
// class Solution {
// public:
//     long long minimumCost(string source, string target, vector<char>&
//     original,
//                           vector<char>& changed, vector<int>& cost) {
//         vector<vector<long long>> adjMatrix(26,
//                                             vector<long long>(26, INT_MAX));
//         floydWarshall(adjMatrix, original, changed, cost);
//         long long result = 0;
//         int n = source.length();
//         for (int i = 0; i < n; i++) {
//             if (source[i] == target[i]) {
//                 continue;
//             }
//             if (adjMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
//                 return -1;
//             }
//             result += adjMatrix[source[i] - 'a'][target[i] - 'a'];
//         }
//         return result;
//     }
//     void floydWarshall(vector<vector<long long>>& adjMatrix,
//                        vector<char>& original, vector<char>& changed,
//                        vector<int>& cost) {
//         for (int i = 0; i < original.size(); i++) {
//             int src = original[i] - 'a';
//             int desti = changed[i] - 'a';
//             adjMatrix[src][desti] =
//                 min(adjMatrix[src][desti], (long long)cost[i]);
//         }
//         for (int k = 0; k < 26; k++) {
//             for (int i = 0; i < 26; i++) {
//                 for (int j = 0; j < 26; j++) {
//                     adjMatrix[i][j] =
//                         min(adjMatrix[i][j], adjMatrix[i][k] +
//                         adjMatrix[k][j]);
//                 }
//             }
//         }
//     }
// };
