// O(N) -->
class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total)
            return "";

        string ans = "";
        char prev = '#';

        for (int i = 0; i < n; i++) {
            for (char ch : {'a', 'b', 'c'}) {

                if (ch == prev)
                    continue;

                int remaining = n - i - 1;
                int count = 1 << remaining;

                if (k > count) {
                    k -= count;
                } else {
                    ans += ch;
                    prev = ch;
                    break;
                }
            }
        }
        return ans;
    }
};

// O(2^N) -->
// class Solution {
// public:
//     vector<string> happyStrings;
//     string getHappyString(int n, int k) {
//         solve(n, "");
//         return happyStrings.size() >= k ? happyStrings[k - 1] : "";
//     }
//     void solve(int n, string currStr) {
//         if (currStr.length() == n) {
//             happyStrings.push_back(currStr);
//             return;
//         }
//         for (char ch : {'a', 'b', 'c'}) {
//             if (!currStr.empty() && currStr.back() == ch)
//                 continue;
//             solve(n, currStr + ch);
//         }
//     }
// };

// O(2^N) -->
class Solution {
public:
    string ans = "";
    int count = 0;
    string getHappyString(int n, int k) {
        string cur = "";
        backtrack(n, k, cur);
        return ans;
    }

    bool backtrack(int& n, int& k, string& cur) {
        if (cur.size() == n) {
            count++;
            if (count == k) {
                ans = cur;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            int len = cur.size();
            if (len > 0 && cur[len - 1] == ch)
                continue;
            cur.append(1, ch);
            if (backtrack(n, k, cur))
                return true;

            cur.pop_back();
        }
        return false;
    }
};
