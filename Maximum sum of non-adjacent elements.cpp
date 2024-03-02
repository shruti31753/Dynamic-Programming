#include <bits/stdc++.h> 
int solve(int ind, vector<int>&nums, vector<int>&dp){
    if(dp[ind] != -1)
        return dp[ind];
    if(ind==0) return nums[ind];
    if(ind<0) return 0;

    int pick = nums[ind]+solve(ind-2, nums, dp);
    int nonPick = 0 + solve(ind-1, nums, dp);

    return dp[ind]=max(pick, nonPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int ind=1;ind<n;ind++){
        int pick = nums[ind];
        if(ind>1)
            pick += prev2;
        int nonPick = 0 + prev;
        int cur = max(pick, nonPick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
    // Write your code here.
}
