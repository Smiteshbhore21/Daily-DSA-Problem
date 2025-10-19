// DFS --> O(n^2)
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        stack<string> stk;
        unordered_set<string> visited;
        stk.push(s);
        visited.insert(s);
        string smallestStr = s;
        while (!stk.empty()) {
            string curr = stk.top();
            stk.pop();
            if (smallestStr > curr) {
                smallestStr = curr;
            }
            string temp = curr;
            for (int i = 1; i < n; i += 2) {
                int chr = temp[i] - '0';
                chr = (chr + a) % 10;
                temp[i] = chr + '0';
            }
            if (!visited.count(temp)) {
                stk.push(temp);
                visited.insert(temp);
            }
            temp = rotate(curr, b);
            if (!visited.count(temp)) {
                stk.push(temp);
                visited.insert(temp);
            }
        }
        return smallestStr;
    }
    string rotate(string s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
        return s;
    }
};

// BFS
// class Solution {
// public:
//     string findLexSmallestString(string s, int a, int b) {
//         int n = s.length();
//         queue<string> que;
//         unordered_set<string> visited;
//         que.push(s);
//         visited.insert(s);
//         string smallestStr = s;
//         while (!que.empty()) {
//             string curr = que.front();
//             que.pop();
//             if (smallestStr > curr) {
//                 smallestStr = curr;
//             }
//             string temp = curr;
//             for (int i = 1; i < n; i += 2) {
//                 int chr = temp[i] - '0';
//                 chr = (chr + a) % 10;
//                 temp[i] = chr + '0';
//             }
//             if (!visited.count(temp)) {
//                 que.push(temp);
//                 visited.insert(temp);
//             }
//             temp = rotate(curr, b);
//             if (!visited.count(temp)) {
//                 que.push(temp);
//                 visited.insert(temp);
//             }
//         }
//         return smallestStr;
//     }
//     string rotate(string s, int b) {
//         reverse(begin(s), end(s));
//         reverse(begin(s), begin(s) + b);
//         reverse(begin(s) + b, end(s));
//         return s;
//     }
// };
