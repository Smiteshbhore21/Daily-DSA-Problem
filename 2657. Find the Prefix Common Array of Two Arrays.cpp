class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);
        vector<int> freq(n + 1, 0);

        int common = 0;

        for (int i = 0; i < n; i++) {

            freq[A[i]]++;
            if (freq[A[i]] == 2)
                common++;

            freq[B[i]]++;
            if (freq[B[i]] == 2)
                common++;

            result[i] = common;
        }

        return result;
    }
};

// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         vector<int> result;
//         unordered_set<int> prefA, prefB;
//         int n = A.size();
//         if (A[0] == B[0])
//             result.push_back(1);
//         else
//             result.push_back(0);
//         prefA.insert(A[0]);
//         prefB.insert(B[0]);
//         for (int i = 1; i < n; i++) {
//             prefA.insert(A[i]);
//             prefB.insert(B[i])
//             int cnt = result.back();
//             if (A[i] == B[i]) {
//                 cnt++;
//                 result.push_back(cnt);
//                 continue;
//             }
//             cnt += prefA.count(B[i]);
//             cnt += prefB.count(A[i]);
//             result.push_back(cnt);
//         }
//         return result;
//     }
// };
