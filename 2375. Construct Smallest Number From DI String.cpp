class Solution {
public:
    string pt;
    int n;
    string smallestNumber(string pattern) {
        pt = pattern;
        n = pattern.size();
        vector<bool> used(10);
        string res;
        vector<int> num(n + 1);
        backtrack(0, num, used, res);
        for (int i = 0; i < num.size(); i++) {
            res.append(to_string(num[i]));
        }
        return res;
    }

    bool backtrack(int index, vector<int>& num, vector<bool>& used,
                   string& res) {
        if (index > n) {
            return true;
        }
        for (int digit = 1; digit <= 9; digit++) {
            if (!used[digit] &&
                (index == 0 || isValid(num[index - 1], digit, pt[index - 1]))) {
                used[digit] = true;
                num[index] = digit;
                if (backtrack(index + 1, num, used, res))
                    return true;
                num[index] = 0;
                used[digit] = false;
            }
        }
        return false;
    }
    bool isValid(int lastDigit, int curDigit, char condition) {
        return (condition == 'I' && lastDigit < curDigit) ||
               (condition == 'D' && lastDigit > curDigit);
    }
};
