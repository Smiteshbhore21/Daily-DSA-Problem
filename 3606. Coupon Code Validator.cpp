class Solution {
public:
    unordered_map<string, int> categories = {
        {"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        vector<pair<int, string>> validCoupons;
        for (int i = 0; i < n; i++) {
            if (isActive[i] && isValid(code[i], businessLine[i])) {
                validCoupons.push_back({categories[businessLine[i]], code[i]});
            }
        }
        sort(validCoupons.begin(), validCoupons.end());
        vector<string> result;
        for (pair<int, string>& coupon : validCoupons) {
            result.push_back(coupon.second);
        }
        return result;
    }

    bool isValid(string& code, string& businessLine) {
        if (code.size() == 0) {
            return false;
        }
        for (const char& ch : code) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9') || (ch == '_'))
                continue;
            return false;
        }

        return categories.find(businessLine) != categories.end();
    }
};
