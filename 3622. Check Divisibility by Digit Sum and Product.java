class Solution {
    public boolean checkDivisibility(int n) {
        int arr = digitProdAndSum(n);

        if (n % arr == 0)
            return true;

        return false;
    }

    public int digitProdAndSum(int n) {
        int[] result = { 0, 1 };

        int temp = n;

        while (temp != 0) {
            result[0] = result[0] + (temp % 10);
            result[1] = result[1] * (temp % 10);

            temp /= 10;
        }

        return result[0] + result[1];
    }
}
