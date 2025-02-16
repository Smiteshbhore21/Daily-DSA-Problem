class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans((n * 2) - 1);
        vector<bool> used(n + 1);
        backtrack(0, used, ans, n);
        return ans;
    }

    bool backtrack(int index, vector<bool>& used, vector<int>& ans,
                   int target) {
        while (index < ans.size() && ans[index] != 0)
            index++;
        if (index == ans.size())
            return true;
        for (int i = target; i >= 1; i--) {
            if (used[i])
                continue;
            if (i == 1) {
                ans[index] = i;
                used[i] = true;
                if (backtrack(index + 1, used, ans, target))
                    return true;
                ans[index] = 0;
                used[i] = false;
            } else if (index + i < ans.size() && ans[index + i] == 0) {
                ans[index] = i;
                ans[index + i] = i;
                used[i] = true;
                if (backtrack(index + 1, used, ans, target))
                    return true;
                ans[index] = 0;
                ans[index + i] = 0;
                used[i] = false;
            }
        }
        return false;
    }
};
