class Solution {
    public static final int MOD = 1_000_000_007;

    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int l = 0, r = n - 1;
        int ans = 0;
        int[] pow2 = new int[n];
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                int diff = r - l;
                ans = (ans + pow2[diff]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
}

// CPP with Binary Expo
// #define MOD 1000000007
// class Solution {
// public:
//     int numSubseq(vector<int>& nums, int target) {
//         sort(begin(nums), end(nums));
//         int n = nums.size();
//         int l = 0, r = n - 1;
//         long long ans = 0;
//         while (l <= r) {
//             if (nums[l] + nums[r] <= target) {
//                 int diff = r - l;
//                 ans = (ans + binaryExpo(2, diff)) % MOD;
//                 l++;
//             } else {
//                 r--;
//             }
//         }
//         return (int)ans;
//     }

//     long long binaryExpo(long long a, long long b) {
//         if (b == 0)
//             return 1;
//         long long half = binaryExpo(a, b / 2);
//         long long res = (half * half) % MOD;
//         if (b % 2 == 1)
//             res = (res * a) % MOD;

//         return res;
//     }
// };
