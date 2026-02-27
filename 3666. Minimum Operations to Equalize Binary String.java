class Solution {
    public int minOperations(String s, int k) {
        int n = s.length();
        int startZeros = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '0') startZeros++;
        }

        if (startZeros == 0) return 0;

        int[] operations = new int[n + 1];
        Arrays.fill(operations, -1);

        TreeSet<Integer> evenSet = new TreeSet<>();
        TreeSet<Integer> oddSet = new TreeSet<>();

        for (int count = 0; count <= n; count++) {
            if (count % 2 == 0)
                evenSet.add(count);
            else
                oddSet.add(count);
        }

        Queue<Integer> que = new LinkedList<>();
        que.offer(startZeros);
        operations[startZeros] = 0;

        if (startZeros % 2 == 0)
            evenSet.remove(startZeros);
        else
            oddSet.remove(startZeros);

        while (!que.isEmpty()) {
            int z = que.poll();

            int minF = Math.max(0, k - (n - z));
            int maxF = Math.min(k, z);

            int minNewZ = z + k - 2 * maxF;
            int maxNewZ = z + k - 2 * minF;

            TreeSet<Integer> currSet =
                    (minNewZ % 2 == 0) ? evenSet : oddSet;

            Integer candidate = currSet.ceiling(minNewZ);

            while (candidate != null && candidate <= maxNewZ) {
                int newZ = candidate;

                operations[newZ] = operations[z] + 1;

                if (newZ == 0)
                    return operations[newZ];

                que.offer(newZ);

                currSet.remove(newZ);
                candidate = currSet.ceiling(minNewZ);
            }
        }

        return -1;
    }
}
