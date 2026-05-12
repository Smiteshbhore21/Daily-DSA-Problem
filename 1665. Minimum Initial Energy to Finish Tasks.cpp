class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int n = tasks.size();
        int l = 0;
        int r = 1e9;

        int result = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(tasks, mid)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }

    bool isPossible(vector<vector<int>>& tasks, int mid) {
        for (vector<int>& task : tasks) {
            int actual = task[0];
            int mininum = task[1];

            if (mininum > mid)
                return false;
            mid -= actual;
        }

        return true;
    }
};
