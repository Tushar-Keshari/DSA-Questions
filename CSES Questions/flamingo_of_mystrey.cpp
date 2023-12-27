#include <bits/stdc++.h>
#include <iostream>
#include<vector>
#include<math.h>
#include<list>
#include<map>
#include<algorithm>
#include<deque>
#include<stack>
#include<bitset>
#include<memory.h>
#include<string>
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

void func(){
    int n;cin>>n;

    ll sum1t02=0,sum2t03=0,sum1t03;
    cout<<"? "<<1<<" "<<2<<endl;
    cin>>sum1t02;
    cout<<"? "<<2<<" "<<3<<endl;
    cin>>sum2t03;
    cout<<"? "<<1<<" "<<3<<endl;
    cin>>sum1t03;

    vector<ll> v(n+1);
    v[1]=sum1t03 - sum2t03;
    v[2]=sum1t02 - v[1];
    v[3]=sum2t03 - v[2];

    for(int i=4;i<=n;i++){
        cout<<"? "<<i-1<<" "<<i<<endl;
        int k;cin>>k;
        v[i]=k-v[i-1];
    }

    cout<<"! ";
    for(auto i=1;i<=n;i++) cout<<v[i]<<" ";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    func();
    return 0;
}