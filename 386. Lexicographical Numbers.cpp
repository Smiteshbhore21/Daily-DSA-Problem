class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; i++)
            solve(i, n, result);
        return result;
    }

    void solve(int curr, int n, vector<int>& result) {
        if (curr > n)
            return;
        result.push_back(curr);
        for (int append = 0; append <= 9; append++) {
            int newNum = curr * 10 + append;
            if (newNum > n)
                return;
            solve(newNum, n, result);
        }
        return;
    }
};

// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<int> ans;
//         unordered_set<int> visited;
//         for (int i = 1; i <= n; i++) {
//             dfs(n, ans, i, visited);
//         }
//         return ans;
//     }
//     void dfs(int& n, vector<int>& ans, int num, unordered_set<int>& visited)
//     {
//         if (num > n)
//             return;
//         if (visited.find(num) == visited.end()) {
//             ans.push_back(num);
//             visited.insert(num);
//         }
//         for (int i = 0; i <= 9; i++) {
//             if ((num * 10) + i > n)
//                 return;
//             dfs(n, ans, (num * 10) + i, visited);
//         }
//         return;
//     }
// };
