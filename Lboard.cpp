public int ways(int n) {
    List<List<Integer>> adj = new LinkedList<>();
    construct(adj);
    int count = 0;
    int[] dp = new int[10];
    dp[0] = 1;
    for(int step = 0; step < n; step++) {
        int[] temp = new int[10];
        for(int i = 0; i < 10; i++) {
            List<Integer> cur = adj.get(i);
            for(int c: cur) temp[c] += dp[i];
        }
        dp = temp;
    }
    for(int item: dp) count += item;
    return count;
}