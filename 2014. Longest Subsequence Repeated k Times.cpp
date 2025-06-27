class Solution {
public:
    string res = "";
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        int freq[26] = {};
        for (const char& x : s) {
            freq[x - 'a']++;
        }
        vector<bool> canUse(26, false);
        vector<int> reqFreq(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                reqFreq[i] = freq[i] / k;
            }
        }
        int maxLen = n / k;
        string curr;
        for (int len = maxLen; len >= 0; len--) {
            vector<int> tempReqFreq = reqFreq;
            if (backtrack(s, curr, canUse, tempReqFreq, k, len)) {
                return res;
            }
        }
        return res;
    }
    bool isSubSeq(string& s, string& sub, int k) {
        int i = 0, j = 0;
        int L = sub.length();
        int n = s.length();

        while (i < n && j < k * L) {
            if (s[i] == sub[j % L])
                j++;
            i++;
        }
        return j == k * L;
    }
    bool backtrack(string& s, string& curr, vector<bool>& canUse,
                   vector<int>& reqFreq, int& k, int& maxLen) {
        if (curr.length() == maxLen) {
            if (isSubSeq(s, curr, k)) {
                res = curr;
                return true;
            }
            return false;
        }
        if ((curr.length() > res.length() ||
             (curr.length() == res.length() && curr > res)) &&
            isSubSeq(s, curr, k)) {
            res = curr;
        }
        for (int i = 25; i >= 0; i--) {
            if (canUse[i] == false || reqFreq[i] == 0)
                continue;
            char ch = i + 'a';
            curr += ch;
            reqFreq[i]--;
            if (backtrack(s, curr, canUse, reqFreq, k, maxLen))
                return true;
            curr.pop_back();
            reqFreq[i]++;
        }
        return false;
    }
};
