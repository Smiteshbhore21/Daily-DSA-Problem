using ll = long long;
class Solution {
public:
    long long kMirror(int k, int n) {
        ll sum = 0;
        int l = 1;
        while (n > 0) {
            int half_length = (l + 1) / 2;
            ll minNum = pow(10, half_length - 1);
            ll maxNum = pow(10, half_length) - 1;
            for (int num = minNum; num <= maxNum; num++) {
                string first_half = to_string(num);
                string second_half(first_half.rbegin(), first_half.rend());
                string pal = "";
                if (l % 2 == 0) {
                    pal = first_half + second_half;
                } else {
                    pal = first_half + second_half.substr(1);
                }

                long long pal_num = stoll(pal);
                string kBase = baseK(pal_num, k);
                if (isPalindrome(kBase)) {
                    sum += pal_num;
                    n--;
                    if(n==0)break;
                }
            }
            l++;
        }
        return sum;
    }

    string baseK(long long num, int& k) {
        string ans = "";
        while (num) {
            ans.push_back(char('0' + (num % k)));
            num /= k;
        }
        return ans;
    }

    bool isPalindrome(string& num) {
        int n = num.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (num[i] != num[j])
                return false;
        }
        return true;
    }
};
