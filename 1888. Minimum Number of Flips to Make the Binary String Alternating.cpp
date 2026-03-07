// Time -> O(n), Space -> O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int result = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;
        int l = 0;
        for (int i = 0; i < 2 * n; i++) {
            char ch1 = (i % 2 == 0) ? '0' : '1';
            char ch2 = (i % 2 == 0) ? '1' : '0';

            if (s[i % n] != ch1)
                flip1++;
            if (s[i % n] != ch2)
                flip2++;
            if (i - l + 1 > n) {
                ch1 = (l % 2 == 0) ? '0' : '1';
                ch2 = (l % 2 == 0) ? '1' : '0';
                if (s[l % n] != ch1)
                    flip1--;
                if (s[l % n] != ch2)
                    flip2--;
                l++;
            }
            if (i - l + 1 == n)
                result = min({result, flip1, flip2});
        }
        return result;
    }
};

// Time -> O(n), Space -> O(n)
// class Solution {
// public:
//     int minFlips(string s) {
//         int n = s.length();
//         s += s;
//         int N = s.length();
//         string s1 = "", s2 = "";
//         for (int i = 0; i < N; i++) {
//             s1 += (i % 2) == 0 ? '0' : '1';
//             s2 += (i % 2) == 0 ? '1' : '0';
//         }
//         int result = INT_MAX;
//         int flip1 = 0;
//         int flip2 = 0;
//         int l = 0;
//         for (int i = 0; i < N; i++) {
//             if (s[i] != s1[i])
//                 flip1++;
//             if (s[i] != s2[i])
//                 flip2++;
//             if (i - l + 1 > n) {
//                 if (s[l] != s1[l])
//                     flip1--;
//                 if (s[l] != s2[l])
//                     flip2--;
//                 l++;
//             }
//             if (i - l + 1 == n)
//                 result = min({result, flip1, flip2});
//         }
//         return result;
//     }
// };
