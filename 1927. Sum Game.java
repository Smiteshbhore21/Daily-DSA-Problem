class Solution {
    public boolean sumGame(String num) {
        int leftKnowSum = 0, rightKnowSum = 0, leftQnMarkCount = 0, rightQnMarkCount = 0;

        int n = num.length();

        for (int i = 0; i < n; i++) {
            if (num.charAt(i) == '?') {
                if (i < n / 2) {
                    leftQnMarkCount++;
                } else {
                    rightQnMarkCount++;
                }
            } else {
                if (i < n / 2) {
                    leftKnowSum += (num.charAt(i) - '0');
                } else {
                    rightKnowSum += (num.charAt(i) - '0');
                }
            }
        }


        int totalQnMarks = leftQnMarkCount + rightQnMarkCount;
        if (totalQnMarks % 2 == 1) {
            return true;
        }

        int left = 2 * leftKnowSum + 9 * leftQnMarkCount;
        int right = 2 * rightKnowSum + 9 * rightQnMarkCount;

        if (left == right) {
            return false;
        }

        return true;
    }
}
