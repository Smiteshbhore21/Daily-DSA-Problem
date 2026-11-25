using ll = long long;
int M = 1e9 + 7;
class Solution {
public:
    int n;
    int base;
    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();
        base = *max_element(begin(nums), end(nums)) + 1;

        int l = 1;
        int r = n;
        int result = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, nums)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }

    bool check(int size, vector<int>& nums) {

        ll hash = 0;
        unordered_map<ll, int> mp;

        ll p = findPower(base, size - 1);

        int i = 0;
        int j = 0;

        while (j < n) {
            hash = (hash * base + nums[j]) % M;

            if (j - i + 1 < size) {
                j++;
            } else {
                mp[hash]++;

                hash = (hash - (p * nums[i]) % M + M) % M;

                i++;
                j++;
            }
        }

        for (auto& it : mp) {
            if (it.second == 1) {
                return true;
            }
        }

        return false;
    }

    ll findPower(ll a, ll b) {
        if (b == 0)
            return 1;

        ll half = findPower(a, b / 2);

        ll result = (half * half) % M;

        if (b % 2 == 1)
            result = (result * a) % M;

        return result;
    }
};
