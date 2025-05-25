class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int result = 0;
        for (string& word : words) {
            string reveredWord = word;
            swap(reveredWord[1], reveredWord[0]);
            if (mp[reveredWord] > 0) {
                result += 4;
                mp[reveredWord]--;
            } else {
                mp[word]++;
            }
        }

        for (auto& it : mp) {
            string word = it.first;
            int count = it.second;
            if (word[0] == word[1] && count > 0) {
                result += 2;
                break;
            }
        }
        return result;
    }
};
