class Solution {
    vector<long long> seg_tree;

    void updateSegTree(long long st_idx, long long start, long long end,
                       long long& query_idx) {
        if (end < query_idx or start > query_idx)
            return;
        if (start == end) {
            seg_tree[st_idx]++;
            return;
        }
        long long mid = start + (end - start) / 2;
        updateSegTree(2 * st_idx, start, mid, query_idx);
        updateSegTree(2 * st_idx + 1, mid + 1, end, query_idx);
        seg_tree[st_idx] = seg_tree[2 * st_idx] + seg_tree[2 * st_idx + 1];
    }
    int rangeSumQuery(long long st_idx, long long start, long long end,
                       long long qs, long long qe) {
        if (qs > end or qe < start)
            return 0;
        if (start >= qs and end <= qe)
            return seg_tree[st_idx];
        long long mid = start + (end - start) / 2;
        long long left_sum = rangeSumQuery(2 * st_idx, start, mid, qs, qe);
        long long right_sum =
            rangeSumQuery(2 * st_idx + 1, mid + 1, end, qs, qe);
        return right_sum + left_sum;
    }

public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size();
        seg_tree = vector<long long>(4 * n + 1, 0);
        unordered_map<long long, long long> nums2_val_idx;
        for (long long i = 0; i < n; i++) {
            nums2_val_idx[nums2[i]] = i;
        }

        updateSegTree(1, 0, n - 1, nums2_val_idx[nums1[0]]);

        long long count_good_triplets = 0;
        for (int i = 1; i < n - 1; i++) {
            long long nums2_idx = nums2_val_idx[nums1[i]];
            long long common_left_ele =
                rangeSumQuery(1, 0, n - 1, 0, nums2_idx);
            long long uncommon_left_ele = (i - common_left_ele);
            long long common_right_ele =
                (n - nums2_idx - 1) - uncommon_left_ele;
            count_good_triplets += common_right_ele * common_left_ele;
            updateSegTree(1, 0, n - 1, nums2_idx);
        }
        return count_good_triplets;
    }
};
