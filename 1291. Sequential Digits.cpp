class Solution {
    public List<Integer> result;

    public List<Integer> sequentialDigits(int low, int high) {
        result = new ArrayList<>();
        for (int i = 1; i <= 9; i++) {
            solve(low, high, i);
        }
        Collections.sort(result);
        return result;
    }

    public void solve(int low, int high, int curr) {

        if (curr >= low && curr <= high) {
            result.add(new Integer(curr));
        }

        for (int i = 1; i < 10; i++) {
            int rem = curr % 10;
            if (rem + 1 == i)
                solve(low, high, curr * 10 + i);
        }
    }
}
