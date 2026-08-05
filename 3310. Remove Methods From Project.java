class Solution {

    private boolean[] sus;

    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        ArrayList<Integer>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        sus = new boolean[n];

        for (int[] edge : invocations) {
            adj[edge[0]].add(edge[1]);
        }

        boolean[] visited = new boolean[n];
        dfs(k, adj, visited);

        for (int[] edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!sus[u] && sus[v]) {
                List<Integer> all = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    all.add(i);
                }
                return all;
            }
        }

        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (!sus[i]) {
                result.add(i);
            }
        }

        return result;
    }

    public void dfs(int node, ArrayList<Integer>[] adj, boolean[] visited) {
        if (visited[node]) {
            return;
        }

        visited[node] = true;
        sus[node] = true;

        for (int next : adj[node]) {
            dfs(next, adj, visited);
        }
    }
}
