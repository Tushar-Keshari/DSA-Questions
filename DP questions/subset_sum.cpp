void solve(vector<int>& num, vector<int>& op, int n, int ind, int sum){
	//base case
	if(ind > n){
		op.push_back(sum);
		return;
	}
	solve(num, op, n, ind+1, sum+num[ind]);
	solve(num,op,n,ind+1,sum);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> op;
	int sum=0;
	int n=num.size();
	solve(num, op, n-1, 0, sum);
	sort(op.begin(),op.end());
	return op;	
}