//code stdio problem
#include <bits/stdc++.h>

using namespace std;

int frogJump(int n, vector<int>& heights) {
    vector<int> dp(n, -1);
    dp[0]=0;
    for(int ind=1;ind<n;ind++){
        int temp = INT_MAX;
        int temp1 = dp[ind-1] + abs(heights[ind]-heights[ind-1]);
        if(ind>1)
            temp = dp[ind-2] + abs(heights[ind]-heights[ind-2]);

        dp[ind] = min(temp, temp1);
    }
    return dp[n-1];
}
