const int MOD = 1e9 + 7;
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        unordered_set<int> edges;
        hFences.push_back(m);
        vFences.push_back(n);
        hFences.push_back(1);
        vFences.push_back(1);
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                edges.insert(abs(hFences[i] - hFences[j]));
            }
        }
        long long maxi = -1;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int side = abs(vFences[i] - vFences[j]);
                if (edges.count(side)) {
                    maxi = max(maxi, 1ll * side * side);
                }
            }
        }
        return maxi % MOD;
    }
};
