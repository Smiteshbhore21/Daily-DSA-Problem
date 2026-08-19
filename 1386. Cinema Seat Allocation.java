class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        HashMap<Integer, Integer> reserve = new HashMap<>();

        for (int[] rowSeat : reservedSeats) {

            int seat = reserve.getOrDefault(rowSeat[0], 0) | (1 << rowSeat[1]);

            reserve.put(rowSeat[0], seat);
        }

        int result = (n - reserve.size()) * 2;

        int groupA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int groupB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int groupC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (Map.Entry<Integer, Integer> entry : reserve.entrySet()) {

            if ((groupA & entry.getValue()) == 0 && (groupC & entry.getValue()) == 0) {
                result += 2;
            } else if ((groupA & entry.getValue()) == 0 || (groupB & entry.getValue()) == 0
                    || (groupC & entry.getValue()) == 0) {
                result++;
            }

        }

        return result;
    }
}
