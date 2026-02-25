class Solution {
    public int[] sortByBits(int[] arr) {
        int maxBitCount = Integer.bitCount(arr[0]);
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            maxBitCount = Math.max(maxBitCount, Integer.bitCount(arr[i]));
        }
        List<ArrayList<Integer>> bucket = new ArrayList<>();
        for (int i = 0; i <= maxBitCount; i++) {
            bucket.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            int bitCnt = Integer.bitCount(arr[i]);
            bucket.get(bitCnt).add(arr[i]);
        }
        int index = 0;
        for (int i = 0; i <= maxBitCount; i++) {
            Collections.sort(bucket.get(i));
            for (int num : bucket.get(i)) {
                arr[index++] = num;
            }
        }
        return arr;
    }
}

// CPP -->
// class Solution {
// public:
//     vector<int> sortByBits(vector<int>& arr) {
//         sort(arr.begin(), arr.end(), [&](const int& a, const int& b) {
//             int aCnt = __builtin_popcount(a);
//             int bCnt = __builtin_popcount(b);
//             if (aCnt == bCnt)
//                 return a < b;
//             return __builtin_popcount(a) < __builtin_popcount(b);
//         });
//         return arr;
//     }
// };
