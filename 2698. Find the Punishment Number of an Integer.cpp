class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string i2 = to_string(i * i);
            if (isPartition(0, i2, i, 0)) {
                res += (i * i);
            }
        }
        return res;
    }

    bool isPartition(int j, string i2, int target, int curSum) {
        int n = i2.size();
        if (j == n)
            return (curSum == target);
        if (curSum > target)
            return false;
        for (int index = j; index < n; index++) {
            int val = stoi(i2.substr(j, index - j + 1));
            if (isPartition(index + 1, i2, target, curSum + val)) {
                return true;
            }
        }
        return false;
    }
};
