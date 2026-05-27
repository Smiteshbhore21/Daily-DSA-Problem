class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        int lastLower[26] = {-1};
        int firstUpper[26] = {-1};

        memset(lastLower, -1, sizeof(lastLower));
        memset(firstUpper, -1, sizeof(firstUpper));

        int count = 0;
        for (int i = 0; i < n; i++) {
            char& ch = word[i];
            if (islower(ch)) {
                lastLower[ch - 'a'] = i;
            } else {
                if (firstUpper[ch - 'A'] == -1) {
                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 && firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i])
                count++;
        }

        return count;
    }
};
