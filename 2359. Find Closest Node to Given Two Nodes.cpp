class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1 = dfs(edges, node1, n), dist2 = dfs(edges, node2, n);
        int ans = -1, minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            edges[i] = max(dist1[i], dist2[i]);
            if (minVal > edges[i]) {
                minVal = edges[i];
                ans = i;
            }
        }
        return ans;
    }

    vector<int> bfs(vector<int>& edges, int& start, int& n) {
        queue<int> q;
        vector<int> dist(n, INT_MAX), visited(n, 0);
        visited[start] = 1;
        q.push(start);
        int dis = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (edges[node] != -1 and !visited[edges[node]]) {
                q.push(edges[node]);
                visited[edges[node]] = 1;
            }
            dist[node] = dis++;
            
        }
        return dist;
    }

    vector<int> dfs(vector<int>& edges, int& start, int& n) {
        stack<int> st;
        vector<int> dist(n, INT_MAX), visited(n, 0);
        visited[start] = 1;
        st.push(start);
        int dis = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (edges[node] != -1 and !visited[edges[node]]) {
                st.push(edges[node]);
                visited[edges[node]] = 1;
            }
            dist[node] = dis++;
        }
        return dist;
    }
};
