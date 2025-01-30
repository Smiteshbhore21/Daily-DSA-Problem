class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }
        vector<int> colors(n);
        for (int node = 0; node < n; node++) {
            if (colors[node] != 0)
                continue;
            colors[node] = 1;
            if (!isBipartite(adjList, node, colors))
                return -1;
        }
        vector<int> distances(n);
        for (int node = 0; node < n; node++) {
            distances[node] = getLongestLength(adjList, node, n);
        }

        int maxNumberOfGroups = 0;
        vector<bool> visited(n);
        for (int node = 0; node < n; node++) {
            if (visited[node])
                continue;
            maxNumberOfGroups += getNumberOfGroupsForComponent(
                adjList, node, distances, visited);
        }
        return maxNumberOfGroups;
    }

    bool isBipartite(vector<vector<int>>& adjList, int node,
                     vector<int>& colors) {
        for (int neighbor : adjList[node]) {
            if (colors[neighbor] == colors[node])
                return false;
            if (colors[neighbor] != 0)
                continue;
            colors[neighbor] = -1 * colors[node];
            if (!isBipartite(adjList, neighbor, colors))
                return false;
        }
        return true;
    }

    int getLongestLength(vector<vector<int>>& adjList, int node, int n) {
        queue<int> qu;
        vector<bool> visited(n, false);
        qu.push(node);
        visited[node] = true;
        int distance = 0;
        while (!qu.empty()) {
            int numOfNodesInLayer = qu.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = qu.front();
                qu.pop();
                for (int neighbor : adjList[currentNode]) {
                    if (visited[neighbor])
                        continue;
                    visited[neighbor] = true;
                    qu.push(neighbor);
                }
            }
            distance++;
        }
        return distance;
    }

    int getNumberOfGroupsForComponent(vector<vector<int>>& adjList, int node,
                                      vector<int>& distances,
                                      vector<bool>& visited) {
        int maxNumberOfGroups = distances[node];
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (visited[neighbor])
                continue;
            maxNumberOfGroups = max(maxNumberOfGroups,
                                    getNumberOfGroupsForComponent(
                                        adjList, neighbor, distances, visited));
        }
        return maxNumberOfGroups;
    }
};
