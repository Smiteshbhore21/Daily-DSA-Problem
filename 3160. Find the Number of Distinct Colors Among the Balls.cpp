class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> colorMap, ballMap;
        int n = queries.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            if (ballMap.find(ball) != ballMap.end()) {
                int oldColor = ballMap[ball];
                colorMap[oldColor]--;
                if (colorMap[oldColor] == 0) {
                    colorMap.erase(oldColor);
                }
            }
            ballMap[ball] = color;
            colorMap[color]++;
            ans.push_back(colorMap.size());
        }
        return ans;
    }
};
