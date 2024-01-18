int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // return f(n,dp);
        int prev0 = 1;
        int prev1 = 1;
        // dp[2] = 2;
        int tmp = 1;
        for(int i = 2;i <= n;i++){
            tmp = prev0 + prev1;
            prev0 = prev1;
            prev1 = tmp;
        }
        return tmp;
    }
