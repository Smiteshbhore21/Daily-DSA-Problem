using ll = long long;
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        ll result = 0;
        ll l = -1e10, r = 1e10;
        while (l <= r) {
            ll midProduct = l + (r - l) / 2;
            ll countSmallest = findCountSmallest(nums1, nums2, midProduct);
            if (countSmallest >= k) {
                result = midProduct;
                r = midProduct - 1;
            } else {
                l = midProduct + 1;
            }
        }
        return result;
    }

    ll findCountSmallest(vector<int>& nums1, vector<int>& nums2,
                         long long midProduct) {
        long long productsCount = 0;

        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 0; i < n1; i++) {
            if (nums1[i] >= 0) {
                int l = 0, r = n2 - 1;
                int m = -1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    ll product = 1ll * nums1[i] * nums2[mid];
                    if (product <= midProduct) {
                        m = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                productsCount += (m + 1);
            } else {
                int l = 0, r = n2 - 1;
                int m = n2;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    ll product = 1ll * nums1[i] * nums2[mid];
                    if (product <= midProduct) {
                        m = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                productsCount += (n2 - m);
            }
        }
        return productsCount;
    }
};
