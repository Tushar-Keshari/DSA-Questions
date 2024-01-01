#include <bits/stdc++.h>
#include <iostream>
#include<algorithm>
#include<bitset>
#include<memory.h>
using namespace std;

#define ll long long int 
#define ld long double
#define line "\n"

const int MOD = 1000000007;
#define rep(i,a,b)      for(ll i=a;i<b;i++)
#define f               first
#define s               second
#define YY              cout<<"Yes"<<endl
#define NN              cout<<"No"<<endl
#define all(v)          sort(v.begin(), v.end())
#define rall(v)         sort(v.rbegin(),v.rend())
#define pb(a)            push_back(a)
#define vec(n)          vector<int> v(n)
#define vecll(n)        vector<long long> v(n)
#define pii             pair<int, int>
#define pll             pair<ll, ll>
#define mii             map<int,int>
#define mll             map<long long ,long long>
#define maxHeapll        priority_queue<ll>
#define minHeapll        priority_queue<ll,vector<ll>,greater<ll>>
#define maxHeap          priority_queue<int>
#define minHeap          priority_queue<int,vector<int>,greater<int>>
#define lb(v,x)         lower_bound(v.begin(),v.end(),x)
#define ub(v,x)         upper_bound(v.begin(),v.end(),x)
#define bs(v,x)         binary_search(v.begin(),v.end(),x)
#define PI              3.1415926535897932384626433832795

bool isPossible(vector<ll>& v,ll k,ll mid,ll sum){
    if(sum - mid <= k) return true;

    ll n=v.size();
    for(int i=n-1;i>=max(1ll,n-mid);i--){
        sum -= v[i];
        ll opLeft = mid - (n-i);
        ll tempSum = sum - v[0] + (n - i + 1)*(v[0]- opLeft);
        if(tempSum<=k) return true;
    }
    return false;
}
void func(){
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];

    ll sum=accumulate(v.begin(),v.end(),0ll);

    sort(v.begin(),v.end());
    ll l = 0 , r = 1e10;
    ll ans=0,m;
    while(l<=r){
        m= l + (r-l)/2;
        if(isPossible(v,k,m,sum)){
            ans = m;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;cin>>t;
    while(t--){
        func();
    }
    return 0;
}