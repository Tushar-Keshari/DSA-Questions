
// bool solve(vector<int>& arr, int n, int sum, vector<vector<bool>>& dp){
// 	if(n>=arr.size() || sum < 0){
// 		return false;
// 	}
// 	if(sum == 0){
// 		return true;
// 	}

// 	if(dp[n][sum] != false) return dp[n][sum];

// 	bool left = solve(arr, n+1, sum-arr[n],dp);
// 	bool right = solve(arr, n+1, sum,dp);
// 	// if(sum>=0){
// 		dp[n][sum]=left||right;
// 	// }
// 	// else{
// 	// 	dp[n][sum]=right;
// 	// }
	
// 	return  dp[n][sum];
// }

bool solveTab(vector<int>& arr, int n, int target){
	vector<vector<bool>> dp(n+1,vector<bool> (target + 1,false));
	
	for(int i=0;i<=n;i++){
		dp[i][0]=true;
	}
	
	for(int ind=n-1;ind>=0;ind--){
		for(int total=0;total<=target;total++){
			bool left=false ;
			if(total-arr[ind] >=0){
			 	left = dp[ind+1][total-arr[ind]];
			}

			bool right = dp[ind+1][total];

			dp[ind][total]=left||right;
		}
	}
	return  dp[0][target];
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here
	
	int sum=0;
	for(auto i:arr){
		sum+=i;
	}
	if(sum&1 || n==1){
		return false;
	}
	else{
		// vector<vector<bool>> dp(n,vector<bool> (sum/2 + 1,false));
		// return solve(arr, 0, sum/2,dp);
		return solveTab(arr, n-1, sum/2);
	}
}
