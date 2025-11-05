using P = pair<int, int>;
class Solution {
public:
    set<P> main, sec;
    int x;
    long long sum;

    void insertInSet(const P& p) {
        if (main.size() < x || p > *main.begin()) {
            sum += (1ll * p.first * p.second);
            main.insert(p);

            if (main.size() > x) {
                auto smallest = *main.begin();
                sum -= (1ll * smallest.first * smallest.second);
                sec.insert(smallest);
                main.erase(smallest);
            }
        } else {
            sec.insert(p);
        }
    }

    void removeFromSet(const P& p) {
        if (main.count(p)) {
            sum -= (1ll * p.first * p.second);
            main.erase(p);

            if (!sec.empty()) {
                auto largest = *sec.rbegin();
                sec.erase(largest);
                main.insert(largest);
                sum += (1ll * largest.first * largest.second);
            }
        } else {
            sec.erase(p);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        sum = 0;
        this->x = x;
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> freq;
        vector<long long> result;
        while (j < n) {
            if (freq[nums[j]] > 0) {
                removeFromSet({freq[nums[j]], nums[j]});
            }
            freq[nums[j]]++;
            insertInSet({freq[nums[j]], nums[j]});

            if (j - i + 1 == k) {
                result.push_back(sum);
                removeFromSet({freq[nums[i]], nums[i]});
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                else
                    insertInSet({freq[nums[i]], nums[i]});

                i++;
            }

            j++;
        }
        return result;
    }
};
