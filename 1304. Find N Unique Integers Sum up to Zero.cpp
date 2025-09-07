class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        int num = 1;
        if (n % 2 == 0) {
            for (int i = 0; i < n; i += 2) {
                ans[i] = num;
                ans[i + 1] = num * -1;
                num++;
            }
        } else {
            for (int i = 1; i < n; i += 2) {
                ans[i] = num;
                ans[i + 1] = num * -1;
                num++;
            }
        }
        return ans;
    }
};
