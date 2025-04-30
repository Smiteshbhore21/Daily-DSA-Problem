class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int& x : nums) {
            if (countDigits(x) % 2 == 0)
                ans++;
        }
        return ans;
    }

    int countDigits(int num) {
        int count = 0;
        while (num) {
            count++;
            num /= 10;
        }
        return count;
    }
};

// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int ans = 0;
//         for (int& x : nums) {
//             if (to_string(x).size() % 2 == 0)
//                 ans++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int ans = 0;
//         for (int& x : nums) {
//             int digits = int(floor(log10(x))) + 1;
//             if (digits % 2 == 0)
//                 ans++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int ans = 0;
//         for (int& x : nums) {
//             if (check(x) % 2 == 0)
//                 ans++;
//         }
//         return ans;
//     }
//     int check(int num) {
//         if (num < 10)
//             return 1;
//         if (num < 100)
//             return 2;
//         if (num < 1000)
//             return 3;
//         if (num < 10000)
//             return 4;
//         if (num < 100000)
//             return 5;
//         return 6;
//     }
// };
