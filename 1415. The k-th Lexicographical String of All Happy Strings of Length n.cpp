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
