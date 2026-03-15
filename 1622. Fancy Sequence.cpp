long long MOD = 1e9 + 7;
using ll = long long;
class Fancy {
public:
    long long add = 0;
    long long mult = 1;
    vector<long long> vals;

    long long binaryExpo(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = binaryExpo(a, b / 2);
        long long result = (half * half) % MOD;

        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    Fancy() {}

    void append(int val) {
        ll x = ((val - add) % MOD + MOD) * binaryExpo(mult, MOD - 2) % MOD;
        vals.push_back(x);
    }

    void addAll(int inc) { add = (add + inc) % MOD; }

    void multAll(int m) {
        mult = (mult * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= vals.size())
            return -1;
        return (vals[idx] * mult + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
