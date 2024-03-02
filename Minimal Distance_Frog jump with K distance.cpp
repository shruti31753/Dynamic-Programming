int solve(int n, vector<int>&height, vector<int>&dp, int k){
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int as = INT_MAX;

        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j] + abs(height[i] - height[i-j]);
                as = min(jump, as);
            }
        }
        dp[i] = as;
        
    }
    return dp[n-1];
}

int minimizeCost(int n, int k, vector<int> &height){
   vector<int>dp(n, -1);
   return solve(n, height, dp, k);
    // Write your code here.
}
