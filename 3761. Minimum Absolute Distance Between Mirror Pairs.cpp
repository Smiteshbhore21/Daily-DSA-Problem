using ll = long long;
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int result = INT_MAX;

        for (int i = 0; i < n; i++) {
            ll rev = reverse(nums[i]);

            if (mp.count(rev)) {
                int sz = mp[rev].size();
                int pos = upper_bound(begin(mp[rev]), end(mp[rev]), i) -
                          begin(mp[rev]);
                if (pos != sz) {
                    result = min(result, abs(i - mp[rev][pos]));
                }
            }
        }

        return result == INT_MAX ? -1 : result;
    }

    ll reverse(int num) {
        ll rev = 0;

        while (num) {
            rev = (rev * 10) + num % 10;
            num /= 10;
        }
        return rev;
    }
};
