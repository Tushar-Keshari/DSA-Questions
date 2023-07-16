int solve(vector<int> &values, vector<int> &weights, int n, int w, vector<vector<int>>& dp){
	//base case
	if(n<0 || w==0) return 0;
	if(dp[n][w]!=-1) return dp[n][w];
	
	//calculation
	if(weights[n]<=w){
		int take = values[n] + solve(values,weights,n-1,w-weights[n],dp);
		int nottake= 0+ solve(values,weights, n-1, w, dp);
		return dp[n][w] = max(take, nottake);
	}
	else{
		return dp[n][w]=solve(values,weights, n-1, w, dp);
	}
	
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>> dp(n+1, vector<int> (w+1,-1));
	return solve(values, weights, n-1 , w, dp);
}