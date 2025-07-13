class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(trainers);
        Arrays.sort(players);
        int ans = 0;
        int pn = players.length, tn = trainers.length;
        int i = 0, j = 0;
        while (i < pn && j < tn) {
            if (players[i] > trainers[j])
                j++;
            else {
                i++;
                j++;
                ans++;
            }
        }
        return ans;
    }
}
