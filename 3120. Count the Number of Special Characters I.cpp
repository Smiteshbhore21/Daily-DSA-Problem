class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool freq[52] = {0};

        for (char& ch : word) {
            if (ch < 97) {
                freq[ch - 'A'] = 1;
            } else {
                freq[ch - 'a' + 26] = 1;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] && freq[i + 26])
                count++;
        }
        return count;
    }
};
