
int MOD = (int)1e9 + 7;

// int solve(vector<int> &arr, int n, int target, vector<vector<int>> &dp) {

//   if (target == 0) {
//     return 1;
//   }
//   if (n == 0) {
//     return (arr[0] == target);
//   }
//   if (dp[n][target] != -1) {
//     return dp[n][target] % MOD;
//   }

//   int incl = 0;
//   if (target - arr[n] >= 0) {
//     incl = solve(arr, n - 1, target - arr[n], dp) % MOD;
//   }

//   int excl = solve(arr, n - 1, target, dp) % MOD;

//   return dp[n][target] = (incl + excl) % MOD;
// }

int solve(vector<int> &arr, int n, int target) {

  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

  for (int i = 0; i < n; i++) {
    dp[i][0] = 1;
  }
  for (int i = n ; i >= 0; i--) {
    for (int total = 0; total <= target; total++) {
      int incl = 0;
      if (total - arr[i] >= 0) {
        incl = dp[i - 1][ total - arr[i]]% MOD;
      }
      int excl = dp[i - 1][total]% MOD;

      dp[n][total] = (incl + excl) % MOD;
    }
  }
  return dp[0][target];
}

int findWays(vector<int> &arr, int k) {
  // Write your code here.
  int n = arr.size();
  //   vector<vector<int>> dp(n+1, vector<int>(k + 1, -1));
  //   return solve(arr, n - 1, k, dp);

  return solve(arr, n - 1, k);
}
