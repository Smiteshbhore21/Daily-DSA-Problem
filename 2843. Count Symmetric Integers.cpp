class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (10 <= i && i <= 99 && i % 11 == 0)
                count++;
            else if (1000 <= i && i <= 9999) {
                int firstHalfSum = 0, secondHalfSum = 0;
                firstHalfSum += (i / 1000);
                firstHalfSum += ((i / 100) % 10);
                secondHalfSum += ((i / 10) % 10);
                secondHalfSum += (i % 10);
                if (secondHalfSum == firstHalfSum)
                    count++;
            }
        }
        return count;
    }
};
