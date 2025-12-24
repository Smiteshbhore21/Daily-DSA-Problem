class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int appleCnt = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int ans = 0;
        for (const int& val : capacity) {
            if (appleCnt <= 0)
                return ans;
            ans++;
            appleCnt -= val;
        }
        return ans;
    }
};
