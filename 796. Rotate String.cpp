class Solution {
public:
    bool rotateString(string s, string goal) {
        int l1 = s.length();
        int l2 = goal.length();
        if (l1 != l2)
            return false;
        int n = l1 * 2;
        s = s + s;

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && s[i] != goal[j]) {
                j--;
            }
            if (s[i] == goal[j]) {
                j++;
            }
            if (j == l2)
                return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int l1 = s.length();
//         int l2 = goal.length();
//         if (l1 != l2)
//             return false;
//         int n = l1;
//         for (int i = 0; i < n; i++) {
//             int j = 0;
//             int idx = i;
//             if (s[i] == goal[j]) {
//                 j++;
//                 idx = (idx + 1) % n;
//                 for (j; j < n; j++, idx = (idx + 1) % n) {
//                     if (s[idx] != goal[j]) {
//                         break;
//                     }
//                 }
//                 if (j == n)
//                     return true;
//             }
//         }
//         return false;
//     }
// };
