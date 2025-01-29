class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size(), groupIndex = 0;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        vector<deque<int>> list(1);
        map<int, int> group;
        list[0].push_back(temp[0]);
        group[temp[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (temp[i] - list[groupIndex].back() > limit) {
                groupIndex++;
                list.push_back(deque<int>());
            }
            group[temp[i]] = groupIndex;
            list[groupIndex].push_back(temp[i]);
        }
        for (int i = 0; i < n; i++) {
            int gi = group[nums[i]];
            nums[i] = list[gi].front();
            list[gi].pop_front();
        }

        return nums;
    }
};
