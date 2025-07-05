// In-place
// Binary Bit Manipulation
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        for (int& num : arr) {
            int val = (num & 65535);
            if (val <= n) {
                arr[val - 1] = (1 << 16); // pow(2,16);
            }
        }
        for (int val = n; val >= 1; val--) {
            if (arr[val - 1] >> 16 == val)
                return val;
        }
        return -1;
    }
};

// sort solution
// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         int freq = 1;
//         int luckyNum = -1;
//         for (int i = 1; i < arr.size(); i++) {
//             if (arr[i] == arr[i - 1])
//                 freq++;
//             else {
//                 if (freq == arr[i - 1])
//                     luckyNum = freq;
//                 freq = 1;
//             }
//         }
//         if (freq == arr.back())
//             luckyNum = freq;
//         return luckyNum;
//     }
// };

// Java --> array solution
// class Solution {
//     public int findLucky(int[] arr) {
//         int luckyNum = -1;
//         int[] freq = new int[501];
//         for (int x : arr) {
//             freq[x]++;
//         }
//         for (int i = 1; i <= 500; i++) {
//             if (i == freq[i]) {
//                 luckyNum = i;
//             }
//         }
//         return luckyNum;
//     }
// }
