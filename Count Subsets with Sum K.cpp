int solve(int ind, int sum, vector<int>& num, vector<vector<int>>& dp, vector<vector<bool>>& chosen) {
    if (sum == 0) {
        // Print the chosen numbers
        for (int i = 0; i <= ind; ++i) {
            if (chosen[i][sum]) {
                cout << num[i] << " ";
                sum -= num[i];
            }
        }
        cout << endl;
        return 1;
    }
    if (ind == 0) {
        if (num[0] == sum) {
            cout << num[0] << endl;
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[ind][sum] != -1) return dp[ind][sum];

    int notTake = solve(ind - 1, sum, num, dp, chosen);
    int take = 0;

    if (num[ind] <= sum) take = solve(ind - 1, sum - num[ind], num, dp, chosen);

    if (take > 0) {
        // Mark the current number as chosen
        chosen[ind][sum] = true;
    }

    return dp[ind][sum] = notTake + take;
}

int findWays(vector<int>& num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    vector<vector<bool>> chosen(n, vector<bool>(tar + 1, false));

    for (int ind = 0; ind < n; ind++) 
        dp[ind][0] = 1;

    if (num[0] <= tar) 
        dp[0][num[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        for (int sum = 0; sum <= tar; sum++) {
            int notTake = dp[ind - 1][sum];
            int take = 0;
            if (num[ind] <= sum) 
                take = dp[ind - 1][sum - num[ind]];

            if (take > 0) {
                // Mark the current number as chosen
                chosen[ind][sum] = true;
            }

            dp[ind][sum] = notTake + take;
        }
    }

    int ways = dp[n - 1][tar];
    

    return ways;
}
