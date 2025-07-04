class Solution {
    public char kthCharacter(long k, int[] operations) {
        if (k == 1)
            return 'a';
        long len = 1;
        int n = operations.length;
        long newK = -1;
        long operaType = -1;
        for (int i = 0; i < n; i++) {
            len *= 2;
            if (len >= k) {
                newK = k - (len / 2);
                operaType = operations[i];
                break;
            }
        }
        char ch = kthCharacter(newK, operations);
        if (operaType == 0) {
            return ch;
        }
        if (ch == 'z')
            return 'a';
        return ++ch;
    }
}
