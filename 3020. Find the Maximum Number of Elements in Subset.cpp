using ll = long long;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<ll, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }

        int maxL = 0;

        if (mp[1] % 2) {
            maxL = mp[1];
        } else {
            maxL = mp[1] - 1;
        }

        for (auto& [key, value] : mp) {
            if (key == 1)
                continue;

            ll curr = key;
            int len = 0;

            while (mp.count(curr) && mp[curr] > 1) {
                len += 2;
                curr = curr * curr;
            }

            if (mp.count(curr) == 1) {
                len += 1;
            } else {
                len -= 1;
            }

            maxL = max(maxL, len);
        }

        return maxL;
    }
};
