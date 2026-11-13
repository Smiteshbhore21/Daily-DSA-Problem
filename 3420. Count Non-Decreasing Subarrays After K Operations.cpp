using ll = long long;
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> cumSum(n);
        cumSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            cumSum[i] = nums[i] + cumSum[i - 1];
        }

        auto rangeSum = [&](int i, int j) -> ll {
            if (i > j)
                return 0;
            return cumSum[j] - ((i > 0) ? cumSum[i - 1] : 0);
        };

        vector<int> NGR(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                NGR[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        vector<ll> operations(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int m = NGR[i];

            ll segmentOprns = (1ll * nums[i] * (m - i)) - rangeSum(i, m - 1);
            operations[i] = segmentOprns + operations[m];
        }

        deque<int> deq;
        ll result = 0;
        int i = 0;
        int j = 0;
        while (j < n) {

            while (!deq.empty() && nums[deq.back()] < nums[j]) {
                deq.pop_back();
            }

            deq.push_back(j);

            // shrink
            while (i <= j) {
                int m = deq.front();

                ll oprnsCnt = operations[i] - operations[m] +
                              (1ll * nums[m] * (j - m + 1)) - rangeSum(m, j);

                if (oprnsCnt <= k) {
                    break;
                }
                i++;

                if (deq.front() < i) {
                    deq.pop_front();
                }
            }

            result += (j - i + 1);
            j++;
        }

        return result;
    }
};
