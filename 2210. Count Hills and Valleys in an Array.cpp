class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hill = 0, valley = 0, n = nums.size();
        int* prevUnequal = new int[n];
        int* nextUnequal = new int[n];
        prevUnequal[0] = nums[0];
        nextUnequal[n - 1] = nums[n - 1];
        for (int i = 1, j = n - 2; i < n; i++, j--) {
            if (nums[i - 1] != nums[i]) {
                prevUnequal[i] = nums[i - 1];
            } else {
                prevUnequal[i] = prevUnequal[i - 1];
            }
            if (nums[j + 1] != nums[j]) {
                nextUnequal[j] = nums[j + 1];
            } else {
                nextUnequal[j] = nextUnequal[j + 1];
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1])
                continue;
            if (nums[i] > prevUnequal[i] && nums[i] > nextUnequal[i])
                hill++;
            else if (nums[i] < prevUnequal[i] && nums[i] < nextUnequal[i])
                valley++;
        }
        return hill + valley;
    }
};
