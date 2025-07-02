// Bottom-Up
class Solution {
    public static final int M = 1_000_000_007;

    public int possibleStringCount(String word, int k) {
        int n = word.length();
        if (n < k)
            return 0;
        ArrayList<Integer> freq = new ArrayList<>();
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (word.charAt(i) != word.charAt(i - 1)) {
                freq.add(count);
                count = 1;
            } else {
                count++;
            }
        }
        freq.add(count);

        long totalPoss = 1;
        for (int x : freq) {
            totalPoss = (totalPoss * x) % M;
        }
        if (freq.size() >= k) {
            return (int) totalPoss;
        }
        ArrayList<ArrayList<Integer>> t = new ArrayList<>(freq.size() + 1);
        // t.ensureCapacity(freq.size() + 1);
        for (int i = 0; i <= freq.size(); i++) {
            ArrayList<Integer> row = new ArrayList<>(Collections.nCopies(k + 1, 0));
            t.add(row);
        }
        for (count = k - 1; count >= 0; count--) {
            t.get(freq.size()).set(count, 1);
        }

        for (int i = freq.size() - 1; i >= 0; i--) {
            int[] prefix = new int[k + 1];
            for (int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h - 1] + t.get(i + 1).get(h - 1)) % M;
            }
            for (count = k - 1; count >= 0; count--) {
                int l = count + 1;
                int r = count + freq.get(i);
                if (r + 1 > k) {
                    r = k - 1;
                }
                if (l <= r) {
                    t.get(i).set(count, (prefix[r + 1] - prefix[l] + M) % M);
                }
            }
        }
        int invalidStringCount = t.get(0).get(0);
        return ((int) totalPoss - invalidStringCount + M) % M;
    }
}

// Recursion + Memoization --> TLE
// class Solution {
//     public static final int M = 1_000_000_007;
//     public static ArrayList<ArrayList<Integer>> t = new ArrayList<>();

//     public int possibleStringCount(String word, int k) {
//         int n = word.length();
//         if (n < k)
//             return 0;
//         ArrayList<Integer> freq = new ArrayList<>();
//         int count = 1;
//         for (int i = 1; i < n; i++) {
//             if (word.charAt(i) != word.charAt(i - 1)) {
//                 freq.add(count);
//                 count = 1;
//             } else {
//                 count++;
//             }
//         }
//         freq.add(count);

//         long totalPoss = 1;
//         for (int x : freq) {
//             totalPoss = (totalPoss * x) % M;
//         }
//         if (freq.size() >= k) {
//             return (int) totalPoss;
//         }
//         t.clear();
//         t.ensureCapacity(freq.size() + 1);
//         for (int i = 0; i <= freq.size(); i++) {
//             ArrayList<Integer> row = new ArrayList<>(Collections.nCopies(k + 1, -1));
//             t.add(row);
//         }
//         int invalidStringCount = solve(0, 0, freq, k);
//         return ((int) totalPoss - invalidStringCount + M) % M;
//     }

//     public static int solve(int i, int count, ArrayList<Integer> freq, int k) {
//         if (i >= freq.size()) {
//             if (count < k)
//                 return 1;
//             return 0;
//         }
//         if (t.get(i).get(count) != -1) {
//             return t.get(i).get(count);
//         }
//         int result = 0;
//         for (int take = 1; take <= freq.get(i); take++) {
//             if (count + take < k) {
//                 result = (result + solve(i + 1, count + take, freq, k)) % M;
//             } else {
//                 break;
//             }
//         }
//         t.get(i).set(count, result);
//         return result;
//     }
// }
