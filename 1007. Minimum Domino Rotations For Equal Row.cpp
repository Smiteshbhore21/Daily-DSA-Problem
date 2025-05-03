class Solution {
public:
    int n = 0;
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        n = tops.size();
        int res = INT_MAX;
        for (int i = 1; i <= 6; i++) {
            int steps = find(tops, bottoms, i);
            if (steps != -1)
                res = min(res, steps);
        }
        return res == INT_MAX ? -1 : res;
    }
    int find(vector<int>& tops, vector<int>& bottoms, int& val) {
        int swapBottom = 0, swapTop = 0;
        for (int i=0; i < n; i++) {
            if (tops[i] != val && bottoms[i] != val)
                return -1;
            else if (tops[i] != val) {
                swapTop++;
            } else if (bottoms[i] != val) {
                swapBottom++;
            }
        }
        return min(swapBottom, swapTop);
    }
};
