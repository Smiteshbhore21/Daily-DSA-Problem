class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int digSum = countDigitSum(nums[i]);
            mp[digSum].push_back(i);
        }
        for (auto& kv : mp) {
            if (kv.second.size() > 1) {
                vector<int> temp = kv.second;
                int first = temp[0], second = temp[1];
                if (nums[first] < nums[second]) {
                    swap(first, second);
                }
                for (int i = 2; i < temp.size(); i++) {
                    if (nums[temp[i]] > nums[first]) {
                        second = first;
                        first = temp[i];
                    } else if (nums[temp[i]] > nums[second]) {
                        second = temp[i];
                    }
                }
                ans = max(ans, nums[first] + nums[second]);
            }
        }
        return ans;
    }

    int countDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
};
