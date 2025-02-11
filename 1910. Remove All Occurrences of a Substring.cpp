class Solution {
public:
    string removeOccurrences(string s, string part) {
        bool subString = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == part[0]) {
                subString = isSub(s, part, i);
            }
            if (subString) {
                s.erase(i, part.size());
                subString = false;
                i = 0;
            } else {
                i++;
            }
        }
        return s;
    }
    bool isSub(const string& s, const string& part, int i) {
        for (int j = 0; j < part.size(); j++, i++)
            if (i >= s.size() || s[i] != part[j])
                return false;

        return true;
    }
};
