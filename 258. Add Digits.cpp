class Solution:
    def addDigits(self, num: int) -> int:
        sum = 0
        while (num // 10):
            sum = num % 10
            temp = num // 10
            while (temp):
                sum += temp % 10
                temp //= 10
            num = sum
        return num
