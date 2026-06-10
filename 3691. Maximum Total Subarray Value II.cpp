using ll = long long;

class SegmentTree {
public:
    vector<int> segmentTree;
    bool isMinTree;
    SegmentTree(vector<int>& nums, bool isMinTree) {
        int n = nums.size();
        this->isMinTree = isMinTree;

        segmentTree.resize(4 * n);

        buildSegmentTree(0, 0, n - 1, nums);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        if (isMinTree)
            segmentTree[i] =
                min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        else
            segmentTree[i] =
                max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    int queryUtil(int i, int start, int end, int l, int r) {

        // Complete overlap
        if (l <= start && end <= r)
            return segmentTree[i];

        // No overlap
        if (end < l || start > r)
            return isMinTree ? INT_MAX : INT_MIN;

        // Partial overlap
        int mid = start + (end - start) / 2;

        int left = queryUtil(2 * i + 1, start, mid, l, r);

        int right = queryUtil(2 * i + 2, mid + 1, end, l, r);

        return isMinTree ? min(left, right) : max(left, right);
    }

    int query(int l, int r, int n) { return queryUtil(0, 0, n - 1, l, r); }
};

class Solution {
public:
    ll getValue(int l, int r, SegmentTree& minST, SegmentTree& maxST, int n) {
        int minEle = minST.query(l, r, n);
        int maxEle = maxST.query(l, r, n);

        return (ll)maxEle - minEle;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree minST(nums, true);
        SegmentTree maxST(nums, false);

        priority_queue<tuple<ll, int, int>> pq;

        for (int l = 0; l < n; l++) {
            ll value = getValue(l, n - 1, minST, maxST, n);
            pq.push({value, l, n - 1});
        }

        ll result = 0;
        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();

            result += value;

            ll nxtBestValue = getValue(l, r - 1, minST, maxST, n);

            pq.push({nxtBestValue, l, r - 1});
        }

        return result;
    }
};
