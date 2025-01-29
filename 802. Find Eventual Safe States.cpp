class Solution {
public:
    bool dfs(int& node, vector<vector<int>>& graph, map<int, bool>& mp) {
        if (mp.find(node) != mp.end())
            return mp[node];
        mp[node] = false;
        for (int i : graph[node])
            if (!dfs(i, graph, mp))
                return false;

        mp[node] = true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        map<int, bool> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (dfs(i, graph, mp))
                ans.push_back(i);

        return ans;
    }
};
