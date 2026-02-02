using ll = long long;
using p = pair<ll, ll>;
class Solution {
public:
    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<p> kMinimum, remaining;

        ll sum = 0;

        int i = 1;
        while (i - dist < 1) {
            kMinimum.insert({nums[i], i});

            sum += nums[i];

            if (kMinimum.size() > k - 1) {
                p temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }
            i++;
        }

        ll result = LLONG_MAX;

        while (i < n) {
            kMinimum.insert({nums[i], i});

            sum += nums[i];

            if (kMinimum.size() > k - 1) {
                p temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }

            result = min(result, sum);

            p remove = {nums[i - dist], i - dist};

            if (kMinimum.count(remove)) {
                kMinimum.erase(remove);
                sum -= remove.first;

                if (!remaining.empty()) {
                    p temp = *remaining.begin();
                    kMinimum.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);
                }
            } else {
                remaining.erase(remove);
            }

            i++;
        }

        return nums[0] + result;
    }
};
