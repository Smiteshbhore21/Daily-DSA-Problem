class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3);
        int curCount = 0, left = 0, n = s.size(), ans = 0;
        for (int right = 0; right < n ; right++) {
            freq[s[right] - 'a']++;
            if (freq[s[right] - 'a'] == 1) {
                curCount++;
            }
            while (curCount == 3) {
                ans += (n - right);
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    curCount--;
                }
                left++;
            }
        }
        return ans;
    }

    bool isAllPresent(vector<int> freq) {
        return freq['a' - 'a'] > 0 && freq['b' - 'a'] > 0 &&
               freq['s' - 'a'] > 0;
    }
};
