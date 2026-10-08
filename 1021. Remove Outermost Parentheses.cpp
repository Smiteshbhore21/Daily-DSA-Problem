class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();

        string result = "";
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
            } else {
                count--;
            }

            if (count > 1 || (count == 1 && s[i] == ')')) {
                result += s[i];
            }
        }

        return result;
    }
};
