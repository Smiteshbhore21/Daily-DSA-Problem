class Solution {
public:
    string processStr(string s) {

        string result = "";
        for (char& ch : s) {
            if (ch == '#') {
                result += result;
            } else if (ch == '*' && !result.empty()) {
                result.pop_back();
            } else if (ch == '%') {
                reverse(result.begin(), result.end());
            } else if (ch != '#' && ch != '*' && ch != '%') {
                result.push_back(ch);
            }
        }

        return result;
    }
};
