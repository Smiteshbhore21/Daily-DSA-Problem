class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 1;
        for (int i = n - 1; i >= 0 && carry; i--) {
            digits[i]++;
            carry = digits[i] / 10;
            if (carry) {
                digits[i] = 0;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }

    // vector<int> plusOne(vector<int>& digits) {
    //     int n = digits.size() - 1, carry = 1;
    //     while (carry) {
    //         digits[n]++;
    //         carry = digits[n] / 10;
    //         if (n > 0 && carry) {
    //             digits[n] = 0;
    //             n--;
    //         } else if (n == 0 && carry) {
    //             digits[0] = 0;
    //             digits.insert(digits.begin(), 1);
    //             carry = 0;
    //         }
    //     }
    //     return digits;
    // }

    // vector<int> plusOne(vector<int>& digits) {
    //     int n = digits.size();
    //     if (digits.back() != 9) {
    //         digits[n - 1]++;
    //         return digits;
    //     }
    //     bool carry = true;
    //     for (int i = n - 1; i >= 0; i--) {
    //         if (digits[i] != 9) {
    //             digits[i]++;
    //             carry = false;
    //             break;
    //         }
    //         digits[i] = 0;
    //     }
    //     if (carry) {
    //         vector<int> ans(n + 1, 0);
    //         ans[0] = 1;
    //         return ans;
    //     }
    //     return digits;
    // }
};
