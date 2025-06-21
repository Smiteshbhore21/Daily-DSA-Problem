class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for (const char& ch : word) {
            freq[ch - 'a']++;
        }
        sort(freq.begin(), freq.end());
        int minDel = word.size();
        int cumulativeDeleted = 0;
        for (int i = 0; i < 26; i++) {
            int del = cumulativeDeleted;
            for (int j = 25; j > i; j--) {
                if (freq[j] - freq[i] <= k)
                    break;
                del += freq[j] - freq[i] - k;
            }
            minDel = min(minDel, del);
            cumulativeDeleted += freq[i];
        }
        return minDel;
    }
};

// class Solution {
// public:
//     int minimumDeletions(string word, int k) {
//         vector<int> freq(26);
//         for (const char& ch : word) {
//             freq[ch - 'a']++;
//         }
//         int minDel = word.size();
//         for (int i = 0; i < 26; i++) {
//             int del = 0;
//             for (int j = 0; j < 26; j++) {
//                 if (i == j)
//                     continue;
//                 if (freq[j] < freq[i]) {
//                     del += freq[j];
//                 } else if (abs(freq[j] - freq[i]) > k) {
//                     del += abs(freq[j] - freq[i] - k);
//                 }
//             }
//             minDel = min(minDel, del);
//         }
//         return minDel;
//     }
// };
