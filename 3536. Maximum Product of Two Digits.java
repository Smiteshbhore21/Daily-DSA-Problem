class Solution {
    public int maxProduct(int n) {
        List<Integer> digits = new ArrayList<>();

        extractDigits(n, digits);

        Collections.sort(digits);

        return digits.get(digits.size() - 1) * digits.get(digits.size() - 2);
    }


    public void extractDigits (int n, List<Integer> digits) {
        while (n != 0) {
            digits.add(n % 10);
            n /= 10;
        }
    }
}
