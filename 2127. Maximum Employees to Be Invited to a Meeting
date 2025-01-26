class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int longestCycle = 0;
        vector<vector<int>> twoLenCycles;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            unordered_set<int> st;
            int start = i;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = true;
                st.insert(cur);
                cur = favorite[cur];
            }
            int len = st.size();
            while (start != cur) {
                len--;
                start = favorite[start];
            }
            longestCycle = max(longestCycle, len);
            if (len == 2) {
                twoLenCycles.push_back({cur, favorite[cur]});
            }
        }
        vector<vector<int>> reverseList(n);
        for (int i = 0; i < n; i++) {
            reverseList[favorite[i]].push_back(i);
        }
        int max2lenCyclePath = 0;
        for (vector<int> arr : twoLenCycles) {
            max2lenCyclePath += s(arr[0], arr[1], reverseList) +
                                s(arr[1], arr[0], reverseList) + 2;
        }
        return max(max2lenCyclePath, longestCycle);
    }

    int s(int& node, int& skip, vector<vector<int>>& reverseList) {
        int len = 0;
        queue<vector<int>> qu;
        qu.push({node,0});
        while (!qu.empty()) {
            vector<int> cur = qu.front();
             len = max(len, cur[1]);
            for (int neighbour : reverseList[cur[0]]) {
                if (neighbour == skip)
                    continue;
                qu.push({neighbour, cur[1] + 1});
            }
            qu.pop();
        }
        return len;
    }
};
