class ProductOfNumbers {
public:
    vector<int> preprod{1};
    ProductOfNumbers() {}

    void add(int num) {
        if (num != 0) {
            preprod.push_back(num * preprod.back());
        } else {
            preprod.clear();
            preprod.push_back(1);
        }
    }

    int getProduct(int k) {
        return k < preprod.size()
                   ? preprod.back() / preprod[preprod.size() - k - 1]
                   : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
