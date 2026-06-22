class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        for (char& ch : text) {
            freq[ch - 'a']++;
        }

        return min({freq['b' - 'a'], freq['a' - 'a'], freq['l' - 'a'] / 2,
                    freq['o' - 'a'] / 2, freq['n' - 'a']});

        int result = INT_MAX;
        string word = "balon";
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;

            if (word.find(ch) != string::npos) {
                result = min(result, freq[i]);
            }
        }

        return result;
    }
};
