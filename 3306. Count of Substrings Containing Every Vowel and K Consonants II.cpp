class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atleast(k, word) - atleast(k + 1, word);
    }
    bool isAllVowelsPresent(vector<int> freq) {
        return (freq['a' - 'a'] > 0 && freq['e' - 'a'] > 0 &&
                freq['i' - 'a'] > 0 && freq['o' - 'a'] > 0 &&
                freq['u' - 'a'] > 0);
    }

    bool isConsonant(char ch) {
        return (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u');
    }

    long long atleast(int k, string words) {
        long long count = 0;
        int curConsonant = 0;
        vector<int> freq(26);
        int n = words.size();
        int left = 0;
        for (int right = 0; right < n; right++) {
            char ch = words[right];
            if (isConsonant(ch))
                curConsonant++;
            freq[ch - 'a']++;

            while (curConsonant>=k && isAllVowelsPresent(freq)) {
                count += (n - right);
                char c = words[left];
                if (isConsonant(c))
                    curConsonant--;
                freq[c - 'a']--;
                left++;
            }
        }
        return count;
    }
};
