class Solution {
public:
    string answerString(string word, int numFriends) {

        int n = word.size(), longestPossible = n - (numFriends - 1);
        if (numFriends == 1)
            return word;
        string ans;
        for (int i = 0; i < n; i++) {
            int canTakeLength = min(longestPossible, n - i);
            ans = max(ans, word.substr(i, canTakeLength));
        }
        return ans;
    }
};
