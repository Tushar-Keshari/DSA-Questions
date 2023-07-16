#include <bits/stdc++.h> 

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int total = accumulate(arr.begin(),arr.end(),0);
	
	vector<vector<bool>> dp(n, vector<bool> (total+1,false));
	for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
	if(arr[0]<=total){
		dp[0][arr[0]]=true;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=total;j++){
			bool incl = false;
			if(arr[i]<=j)
				incl =  dp[i-1][j-arr[i]];

			bool excl = dp[i-1][j];

			dp[i][j]=incl|excl;
		}
	}
	int ans=1e9;
	for(int i=0;i<=total/2;i++){
		if(dp[n-1][i]){
			// ans.push_back(i);
			 ans=min(ans,abs((total-i)-i));
		}
	}
	return ans;
}
