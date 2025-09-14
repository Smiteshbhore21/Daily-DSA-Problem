class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exactMatch(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseError, vowelError;
        for (const string& s : wordlist) {
            string lower = "", vowelLetter = "";
            for (const char& ch : s) {
                lower.push_back(
                    ((ch >= 65 && ch <= 90) ? std::tolower(ch) : ch));
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' ||
                    ch == 'O' || ch == 'U') {
                    vowelLetter += '*';
                } else {
                    vowelLetter.push_back(
                        ((ch >= 65 && ch <= 90) ? std::tolower(ch) : ch));
                }
            }
            if (caseError.find(lower) == caseError.end())
                caseError[lower] = s;
            if (vowelError.find(vowelLetter) == vowelError.end())
                vowelError[vowelLetter] = s;
        }
        vector<string> ans;
        for (const string& s : queries) {
            if (exactMatch.count(s)) {
                ans.push_back(s);
            } else {
                string lower = "", vowelLetter = "";
                for (const char& ch : s) {
                    lower.push_back(
                        ((ch >= 65 && ch <= 90) ? std::tolower(ch) : ch));
                    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                        ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' ||
                        ch == 'O' || ch == 'U') {
                        vowelLetter += '*';
                    } else {
                        vowelLetter.push_back(
                            ((ch >= 65 && ch <= 90) ? std::tolower(ch) : ch));
                    }
                }
                if (caseError.find(lower) != caseError.end()) {
                    ans.push_back(caseError[lower]);
                } else if (vowelError.find(vowelLetter) != vowelError.end()) {
                    ans.push_back(vowelError[vowelLetter]);
                } else {
                    ans.push_back("");
                }
            }
        }
        return ans;
    }
};
