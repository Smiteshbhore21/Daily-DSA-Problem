class Solution {
    public boolean isValid(String word) {
        char[] wordArr = word.toCharArray();
        int n = wordArr.length;
        boolean v = false, c = false;
        if (n < 3)
            return false;
        for (char ch : wordArr) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                v = true;
            } else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                v = true;
            } else if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
                c = true;
            } else if (ch >= 48 && ch <= 57) {

            } else {
                return false;
            }
        }
        return v && c;
    }
}
