class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        result = 0

        left, right, dash = 0, 0, 0

        for i in moves:
            if i == 'L':
                left += 1
            elif i == 'R':
                right += 1
            else:
                dash += 1

        return abs(left - right) + dash;
