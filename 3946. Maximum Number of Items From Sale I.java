// Bottom up -->
class Solution {
    int cheapestPrice = Integer.MAX_VALUE;
    List<Integer> copies;

    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;

        copies = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            cheapestPrice = Math.min(cheapestPrice, items[i][1]);

            int copy = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (items[j][0] % items[i][0] == 0)
                    copy++;
            }
            copies.add(copy);
        }

        int[][] dp = new int[n + 1][budget + 1];
        for (int i = 0; i <= budget; i++) {
            dp[0][i] = i / cheapestPrice;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= budget; j++) {
                int take = 0;
                int skip = 0;
                int price = items[i - 1][1];
                if (price <= j)
                    take = 1 + copies.get(i - 1) + dp[i - 1][j - price];

                skip = dp[i - 1][j];
                dp[i][j] = Math.max(take, skip);
            }
        }

        return dp[n][budget];
    }

}

// Recursion + Memo -->
// class Solution {
//     int cheapestPrice = Integer.MAX_VALUE;
//     List<Integer> copies;
//     int[][] memo;

//     public int maximumSaleItems(int[][] items, int budget) {
//         int n = items.length;

//         copies = new ArrayList<>();
//         memo = new int[n + 1][budget + 1];

//         for (int[] row : memo) {
//             Arrays.fill(row, -1);
//         }

//         for (int i = 0; i < n; i++) {
//             cheapestPrice = Math.min(cheapestPrice, items[i][1]);

//             int copy = 0;
//             for (int j = 0; j < n; j++) {
//                 if (i == j)
//                     continue;

//                 if (items[j][0] % items[i][0] == 0)
//                     copy++;
//             }
//             copies.add(copy);
//         }

//         return solve(n, budget, items);
//     }

//     public int solve(int n, int budget, int[][] items) {
//         if (n == 0) {
//             return budget / cheapestPrice;
//         }

//         if (memo[n][budget] != -1)
//             return memo[n][budget];

//         int take = 0;
//         int skip = 0;
//         int price = items[n - 1][1];

//         if (price <= budget)
//             take = 1 + copies.get(n - 1) + solve(n - 1, budget - price, items);

//         skip = solve(n - 1, budget, items);

//         memo[n][budget] = Math.max(take, skip);

//         return memo[n][budget];
//     }
// }
