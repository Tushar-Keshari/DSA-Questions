#include <bits/stdc++.h> 
bool solve(int n, int k, vector<int> &arr){
    //base
    vector<vector<bool>> dp(n, vector<bool> (k, false));
    
    if(k==0)return true;
    if(n<0) return false;

    if(dp[n][k]!=-1) return dp[n][k];

    int ans1,ans2=0;
    ans1=dp[n-1][k];
    if(k-arr[n]>=0){
        ans2= dp[n-1][k-arr[n]];
    }
    

    return dp[n][k]= ans1||ans2;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // vector<vector<int>> dp(n, vector<int> (k+1, -1));
    // // Write your code here.
    // return solve(n-1,k,arr,dp);

    solve(n-1,k,arr);
}