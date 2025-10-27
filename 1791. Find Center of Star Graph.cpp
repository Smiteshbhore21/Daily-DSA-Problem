class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj(n+2, 0);
        for (vector<int>& e : edges) {
            adj[e[0]]++;
            adj[e[1]]++;
        }
        return max_element(adj.begin(), adj.end()) - adj.begin();
    }
};
