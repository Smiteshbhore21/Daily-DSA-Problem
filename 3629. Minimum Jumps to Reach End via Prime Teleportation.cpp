class Solution {
public:
    vector<bool> isPrime;
    void buildSieve(int maxEle) {
        isPrime.resize(maxEle + 1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int num = 2; num * num <= maxEle; num++) {
            if (isPrime[num]) {
                for (int mult = num * num; mult <= maxEle; mult += num) {
                    isPrime[mult] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        int maxEle = 0;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxEle = max(nums[i], maxEle);
        }

        buildSieve(maxEle);

        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        unordered_set<int> seen;
        int steps = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int i = que.front();
                que.pop();

                if (i == n - 1) {
                    return steps;
                }

                if (i - 1 >= 0 && !visited[i - 1]) {
                    que.push(i - 1);
                    visited[i - 1] = true;
                }

                if (i + 1 < n && !visited[i + 1]) {
                    que.push(i + 1);
                    visited[i + 1] = true;
                }

                if (!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                for (int mult = nums[i]; mult <= maxEle; mult += nums[i]) {
                    if (!mp.count(mult)) {
                        continue;
                    }

                    for (int& j : mp[mult]) {
                        if (!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]);
            }
            steps++;
        }
        return steps;
    }
};
