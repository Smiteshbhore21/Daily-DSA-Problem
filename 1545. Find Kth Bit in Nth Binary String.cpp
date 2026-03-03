class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1)
            return '0';

        int length = (1 << n) - 1;

        if (k < ceil(length / 2.0))
            return findKthBit(n - 1, k);
        else if (k == ceil(length / 2.0))
            return '1';
        else {
            char ch = findKthBit(n - 1, length - (k - 1));
            return ch == '0' ? '1' : '0';
        }
    }
};

// class Solution {
// public:
//     unordered_map<string, string> memo;
//     char findKthBit(int n, int k) {
//         string s = formString(n, "0", 1);
//         cout << s << endl;
//         return s[k - 1];
//     }
//     string formString(const int& n, string currStr, int ops) {
//         if (ops == n)
//             return currStr;
//         string key = currStr + "_" + to_string(ops);
//         if (memo.find(key) != memo.end())
//             return memo[key];
//         string revert = "";
//         for (char ch : currStr) {
//             revert += ('1' == ch ? '0' : '1');
//         }
//         reverse(revert.begin(), revert.end());
//         string newStr = currStr + '1' + revert;
//         return memo[key] = formString(n, newStr, ops + 1);
//     }
// };
