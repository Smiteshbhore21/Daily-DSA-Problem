class Solution {
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] res = new long[n];

        Map<Integer, Long> count = new HashMap<>();
        Map<Integer, Long> sum = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            if (count.containsKey(val)) {
                res[i] += count.get(val) * i - sum.get(val);
            }

            count.put(nums[i], count.getOrDefault(nums[i], 0L) + 1);
            sum.put(nums[i], sum.getOrDefault(nums[i], 0L) + i);
        }

        sum.clear();
        count.clear();

        for (int i = n - 1; i >= 0; i--) {
            int val = nums[i];

            if (count.containsKey(val)) {
                res[i] += sum.get(val) - count.get(val) * i;
            }

            count.put(nums[i], count.getOrDefault(nums[i], 0L) + 1);
            sum.put(nums[i], sum.getOrDefault(nums[i], 0L) + i);
        }
        return res;
    }
}

// TLE -->
// class Solution {
//     public long[] distance(int[] nums) {
//         int n = nums.length;
//         HashMap<Integer, List<Integer>> mp = new HashMap<>();
//         long[] result = new long[n];
//         for (int i = 0; i < n; i++) {
//             List<Integer> list = mp.getOrDefault(nums[i], new ArrayList<>());
//             list.add(i);
//             mp.put(nums[i], list);
//         }
//         for (int i = 0; i < n; i++) {
//             long sum = 0;
//             for (Integer idx : mp.get(nums[i])) {
//                 if (idx == i)
//                     continue;
//                 sum += Math.abs(i - idx);
//             }
//             result[i] = sum;
//         }
//         return result;
//     }
// }
