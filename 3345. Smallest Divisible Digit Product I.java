class Solution {
    public int smallestNumber(int n, int t) {

        int prod = 0;
        for (int i = 0; i < 10; i++) {
            prod = digitProduct(n);
            if (prod % t == 0) {
                return n;
            }
            n++;
        }

        return n;
    }

    private int digitProduct(int num) {
        int temp = num;
        int prod = 1;

        while (temp != 0) {
            int rem = temp % 10;
            prod *= rem;
            temp /= 10;
        }

        return prod;
    }
}
