using ll = long long;
class Solution {
public:
    int minimumPairRemoval(vector<int>& temp) {
        int n = temp.size();

        set<pair<ll, int>> minPairSet;
        vector<int> prevIndex(n), nextIndex(n);
        vector<ll> nums;

        for (int i = 0; i < n; i++) {
            prevIndex[i] = i - 1;
            nextIndex[i] = i + 1;
            nums.push_back(temp[i]);
        }

        int badPairs = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                badPairs++;

            minPairSet.insert({nums[i - 1] + nums[i], i - 1});
        }

        int ops = 0;
        while (badPairs) {
            int first = minPairSet.begin()->second;
            int second = nextIndex[first];

            int first_left = prevIndex[first];
            int second_right = nextIndex[second];

            minPairSet.erase(minPairSet.begin());

            if (nums[first] > nums[second]) {
                badPairs--;
            }

            // {d, (a, b)}
            if (first_left >= 0) {
                if (nums[first_left] > nums[first] &&
                    nums[first_left] <= nums[first] + nums[second]) {
                    badPairs--;
                } else if (nums[first_left] <= nums[first] &&
                           nums[first_left] > nums[first] + nums[second]) {
                    badPairs++;
                }
            }

            // {(a, b), d}
            if (second_right < n) {
                if (nums[second_right] >= nums[second] &&
                    nums[second_right] < nums[first] + nums[second]) {
                    badPairs++;
                } else if (nums[second_right] < nums[second] &&
                           nums[second_right] >= nums[first] + nums[second]) {
                    badPairs--;
                }
            }

            if (first_left >= 0) {
                minPairSet.erase({nums[first_left] + nums[first], first_left});
                minPairSet.insert(
                    {nums[first_left] + nums[first] + nums[second],
                     first_left});
            }

            if (second_right < n) {
                minPairSet.erase({nums[second] + nums[second_right], second});
                minPairSet.insert(
                    {nums[second_right] + nums[first] + nums[second], first});

                prevIndex[second_right] = first;
            }

            nextIndex[first] = second_right;
            nums[first] += nums[second];

            ops++;
        }
        return ops;
    }
};
