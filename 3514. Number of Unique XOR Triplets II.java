class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int maxElement = 0;
        for (int num : nums) {
            maxElement = Math.max(maxElement, num);
        }

        int maxPossibleXor = 1;
        while (maxPossibleXor <= maxElement) {
            maxPossibleXor <<= 1;
        }

        boolean[] uniquePairs = new boolean[maxPossibleXor];
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                uniquePairs[nums[i] ^ nums[j]] = true;
            }
        }

        boolean[] uniqueTriplets = new boolean[maxPossibleXor];
        for (int val = 0; val < maxPossibleXor; val++) {
            if (uniquePairs[val]) {
                for (int num : nums) {
                    uniqueTriplets[val ^ num] = true;
                }
            }
        }

        int uniqueCount = 0;
        for (boolean present : uniqueTriplets) {
            if (present) {
                uniqueCount++;
            }
        }

        return uniqueCount;
    }
}

// class Solution {
//     public int uniqueXorTriplets(int[] nums) {
//         HashSet<Integer> n2OX = new HashSet<>();
//         int n = nums.length;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 n2OX.add(nums[i] ^ nums[j]);
//             }
//         }
//         HashSet<Integer> result = new HashSet<>();
//         for (Integer val : n2OX) {
//             for (int i = 0; i < n; i++) {
//                 result.add(val ^ nums[i]);
//             }
//         }
//         return result.size();
//     }
// }
