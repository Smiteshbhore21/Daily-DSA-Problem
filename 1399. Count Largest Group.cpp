class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxSize = 0, count = 0;
        for (int i = 1; i <= n; i++) {
            int digSum = digitSum(i);

            mp[digSum]++;
            if (mp[digSum] == maxSize) {
                count++;
            } else if (mp[digSum] > maxSize) {
                maxSize = mp[digSum];
                count = 1;
            }
        }
        return count;
    }
};
