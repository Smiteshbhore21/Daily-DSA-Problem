class Solution {
public:
    char findKthBit(int n, int k) {
        string s = formString(n, "0", 1);
        cout << s << endl;
        return s[k-1];
    }

    string formString(const int& n, string currStr, int ops) {
        if (ops == n)
            return currStr;
        string revert = "";
        for (char ch : currStr) {
            revert += ('1' == ch ? '0' : '1');
        }
        reverse(revert.begin(), revert.end());
        string newStr = currStr + '1' + revert;
        return formString(n, newStr, ops + 1);
    }
};
