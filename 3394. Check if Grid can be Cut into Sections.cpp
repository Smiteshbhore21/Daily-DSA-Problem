class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        int countPartX = 0, countPartY = 0, last = 0;
        for (vector<int>& x : rectangles) {
            if (last <= x[0]) {
                countPartX++;
            }
            last = max(last, x[2]);
        }
        last = 0;
        sort(rectangles.begin(), rectangles.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        for (vector<int>& x : rectangles) {
            if (last <= x[1]) {
                countPartY++;
            }
            last = max(last, x[3]);
        }
        return (countPartY >= 3 || countPartX >= 3);
    }
};
