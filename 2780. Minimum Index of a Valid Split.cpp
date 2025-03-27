class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int n = nums.size(), maxEle = nums[0];
        int count = 0, freq = 1;

        // Moore's Voting Algo -->
        for (int i = 1; i < n; i++) {
            if (nums[i] != maxEle)
                freq--;
            else
                freq++;
            if (freq == 0) {
                freq = 1;
                maxEle = nums[i];
            }
        }

        // Freq count of MaxElement
        for (int i = 0; i < n; i++)
            if (nums[i] == maxEle)
                count++;
        

        int prefixCount = 0;

        // Valid Split Check
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxEle) {
                prefixCount++;
                if (((prefixCount * 2) > i + 1) &&
                    (((count - prefixCount) * 2) > n - i - 1))
                    return i;
            }
        }

        return -1;

        // int n = nums.size(), maxEle = nums[0];
        // unordered_map<int, int> count;
        // for (int i = 0; i < n; i++) {
        //     count[nums[i]]++;
        //     if (count[nums[i]] > count[maxEle])
        //         maxEle = nums[i];
        // }
        // int countMax = 0;
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == maxEle) {
        //         countMax++;
        //         if (((countMax * 2) > i + 1) &&
        //             (((count[maxEle] - countMax) * 2) > n - i - 1))
        //             return i;
        //     }
        // }

        // return -1;
    }
};
