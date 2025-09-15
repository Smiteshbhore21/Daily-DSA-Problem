class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> brokenKeys(26, false);
        for (const char& ch : brokenLetters) {
            brokenKeys[ch - 'a'] = true;
        }
        int wordsCanType = 0;
        bool canType = true;
        for (const char& ch : text) {
            if (ch == ' ') {
                if (canType) {
                    wordsCanType++;
                }
                canType = true;
            } else if (brokenKeys[ch - 'a']) {
                canType = false;
            }
        }
        if (canType) {
            wordsCanType++;
        }
        return wordsCanType;
    }
};
