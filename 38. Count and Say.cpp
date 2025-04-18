class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while (--n) {
            int count = 1, ansSize = ans.size();
            string temp = "";
            for (int i = 1; i <= ansSize; i++) {
                if (i < ansSize && ans[i - 1] == ans[i]) {
                    count++;
                } else {
                    temp += to_string(count) + ans[i - 1];
                    count = 1;
                }
            }
            ans = temp;
        }
        return ans;
    }
};
