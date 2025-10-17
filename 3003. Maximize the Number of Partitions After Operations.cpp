class Solution {
public:
    unordered_map<long long, int> dp;
    int maxPartitionsAfterOperations(string s, int k) {
        return solve(s, k, 0, 0, true) + 1;
    }
    int solve(string& s, int& k, long long i, long long uniqChars, bool canChange) {
        long long key = ((i << 27) | (uniqChars << 1) | canChange);
        if (s.size() <= i)
            return 0;

        if(dp.find(key) != dp.end())
            return dp[key];

        int charIndex = s[i] - 'a';
        long long updatedChars = uniqChars | (1 << charIndex);
        int uniqCharCount = __builtin_popcount(updatedChars);

        int result = 0;
        if (uniqCharCount > k) {
            result = 1 + solve(s, k, i + 1, (1 << charIndex), canChange);
        } else {
            result = solve(s, k, i + 1, updatedChars, canChange);
        }

        if (canChange) {
            for (int newCharIndex = 0; newCharIndex < 26; newCharIndex++) {
                long long newChars = uniqChars | (1 << newCharIndex);
                int newUniqCharCount = __builtin_popcount(newChars);

                if (newUniqCharCount > k) {
                    result = max(result, 1 + solve(s, k, i + 1,
                                                   (1 << newCharIndex), false));
                } else {
                    result = max(result, solve(s, k, i + 1, newChars, false));
                }
            }
        }
        return dp[key] = result;
    }
};
