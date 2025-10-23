class Solution {
public:
    bool hasSameDigits(string str) {
        while (str.size() != 2) {
            int n = str.length();
            string temp = "";
            for (int i = 1; i < n; i++) {
                int a = str[i - 1] - '0';
                int b = str[i] - '0';
                temp.push_back((a + b) % 10);
            }
            str = temp;
        }
        return str[0] == str[1];
    }
};
