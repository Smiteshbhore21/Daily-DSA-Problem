// BottomUp + Improved -->
class Solution {
    private static final int MOD = 1_000_000_007;

    public int subsequencePairCount(int[] nums) {
        int n = nums.length;

        int maxEle = Arrays.stream(nums).max().getAsInt();

        int[][] prev = new int[maxEle + 1][maxEle + 1];

        for (int first = 0; first <= maxEle; first++) {
            for (int second = 0; second <= maxEle; second++) {
                boolean bothNonEmpty = (first != 0 && second != 0);
                boolean gcdMatch = (first == second);

                prev[first][second] = (bothNonEmpty && gcdMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i > -1; i--) {
            int[][] curr = new int[maxEle + 1][maxEle + 1];
            for (int first = maxEle; first >= 0; first--) {
                for (int second = maxEle; second >= 0; second--) {

                    int skip = prev[first][second];
                    int take1 = prev[Solution.gcd(first, nums[i])][second];
                    int take2 = prev[first][Solution.gcd(second, nums[i])];

                    curr[first][second] = (int) (((long) take1 + take2 + skip) % MOD);
                }
            }
            prev = curr;
        }

        return prev[0][0];

    }

    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

// BottomUp -->
// class Solution {
//     private static final int MOD = 1_000_000_007;
//     public int subsequencePairCount(int[] nums) {
//         int n = nums.length;
//         int maxEle = Arrays.stream(nums).max().getAsInt();
//         int[][][] t = new int[n + 1][maxEle + 1][maxEle + 1];
//         for (int first = 0; first <= maxEle; first++) {
//             for (int second = 0; second <= maxEle; second++) {
//                 boolean bothNonEmpty = (first != 0 && second != 0);
//                 boolean gcdMatch = (first == second);
//                 t[n][first][second] = (bothNonEmpty && gcdMatch) ? 1 : 0;
//             }
//         }
//         for (int i = n - 1; i > -1; i--) {
//             for (int first = maxEle; first >= 0; first--) {
//                 for (int second = maxEle; second >= 0; second--) {
//                     int skip = t[i + 1][first][second];
//                     int take1 = t[i + 1][Solution.gcd(first, nums[i])][second];
//                     int take2 = t[i + 1][first][Solution.gcd(second, nums[i])];
//                     t[i][first][second] = (int) (((long) take1 + take2 + skip) % MOD);
//                 }
//             }
//         }
//         return t[0][0][0];
//     }

//     public static int gcd(int a, int b) {
//         while (b != 0) {
//             int temp = b;
//             b = a % b;
//             a = temp;
//         }
//         return a;
//     }
// }

// Recursion + Memo -->
// class Solution {
//     private static final int MOD = 1_000_000_007;
//     private int[][][] memo = new int[201][201][201];
//     public int subsequencePairCount(int[] nums) {
//         for (int i = 0; i < 201; i++) {
//             for (int j = 0; j < 201; j++) {
//                 Arrays.fill(memo[i][j], -1);
//             }
//         }
//         return solve(nums, 0, 0, 0);
//     }
//     public int solve(int[] nums, int i, int first, int second) {
//         if (i == nums.length) {
//             if (first != 0 && second != 0 && first == second) {
//                 return 1;
//             }
//             return 0;
//         }
//         if (memo[i][first][second] != -1)
//             return memo[i][first][second];
//         int skip = solve(nums, i + 1, first, second);
//         int take1 = solve(nums, i + 1, Solution.gcd(first, nums[i]), second);
//         int take2 = solve(nums, i + 1, first, Solution.gcd(second, nums[i]));
//         memo[i][first][second] = (int)(((long)take1 + take2 + skip) % MOD);
//         return memo[i][first][second];
//     }
//     public static int gcd(int a, int b) {
//         while (b != 0) {
//             int temp = b;
//             b = a % b;
//             a = temp;
//         }
//         return a;
//     }
// }
