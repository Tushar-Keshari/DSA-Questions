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

// #define
// ((a+b)%M ) = ((a%M)+(b%M))%M
// (a*b)%M=(a%m * b%m)%M 
// (a-b)%M=((a%M)-(b%M))%M
// (a/b)%M=((a%M)* (b^-1)%M)%M

//#define priority_queue
//priority_queue<int> maxi;      max heap
//priority_queue<int,vector<int>,greater<int>> mini;        min heap
//priority_queue<pair<int.int>,vector<pair<int,int>>,greater<pair<int,int>>;      forpair of priority queue
//functions
//mini.push() , mini.pop(),mini.top(),mini.size();

//stack
//     stack<int>s;
//     s.push(2);
//     s.push(3);

//     while(!s.empty())
//     {
//         cout<<s.top()<<endl;
//         s.pop();
//     }

//queue
//     queue<int>q;
//     q.push(2);
//     q.push(3);

//     while(!q.empty())
//     {
//         cout<<q.front()<<endl;
//         q.pop();
//     }

// // inbuild function
// int min= *min_element(v.begin(,v.end())); give min _element
// int max= *max_element(v.begin(,v.end())); give max _element

//bit manupulation
// AND (&)  OR(|)   XOR(^)    left shift  1<<1==2^1  right shift 1>>1==1/2 
// 0 0 0    0 0 0   0 0 0     3<<1=>11==110          3>>1=>11==1
// 0 1 0    0 1 1   0 1 1     3<<2=>11==1100         6>>1=>110->11
// 1 0 0    1 0 1   1 0 1                            6>>2=>110->1
// 1 1 1    1 1 1   1 1 1

// set bit==1 ,unset bit==0
//count set bit __builtin_popcount(a)
// toggle-> any bit set to unset and unset to set printBinary(a^(1<<i))
// void printBinary(int num)
// {
//     for(int i=10;i>=0;i--)
//     {
//         cout<<((num>>i)&1);
//     }
// }

//LCM(a,b)=a*b/__gcd(a,b);

vector<vector<int>> subset(vector<int> nums){
    int n = nums.size();
    int subset = (1<<n);
    vector<vector<int>> result;
    for(int mask = 0 ; mask < subset ; mask++){
        vector<int> subsets;
        for(int j = 0 ; j < n ; j++){
            if((mask  & (1<< j)) != 0){
                subsets.push_back(nums[j]);
            }
        }
        result.push_back(subsets);
    }
    return result;
}
int expo_power(int a , int b){
    //base case 
    if(b == 1) return a;

    int result = 1;
    if(b & 1) // odd
    result = a * expo_power(a,b/2) * expo_power(a,b/2);
    else 
    result = expo_power(a,b/2) * expo_power(a , b/2); 

    return result;

}
void printBinary(int a){
    for(int i=10 ; i>=0 ; i--){
        cout<< ((a >> i) & 1);
    }
    cout<<endl;
}

void func(){
    ll n,m ;
    cin>>n>>m;
    cout<<max(n,m)<<endl;
}
void func2(){
    ll n;cin>>n;
    map<ll,ll> indegree;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        indegree[a-1]++;
        indegree[b-1]++;
    }
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(indegree[i]==1){
            cnt++;
        }
    }
    cout<<ceil((cnt-1)/2)+1<<endl;

}
void func3(){
    ll n;cin>>n;
    string s, sub;cin>>s;
    char cur = 'a';
    ll cnt = 0, cost, pos=0;
    for(ll i=n-1;i>=0;i--)
        if(s[i]>=cur) cnt++, sub+=s[i], cur = s[i], s[i]='#';

        cost = cnt - count(sub.begin(),sub.end(),sub.back());
        // cout<<sub.back()<<" "<<count(sub.begin(),sub.end(),sub.back())<<endl;
    
    // cout<<s<<endl;

    for(int i=0;i<n;i++){
        if(s[i]=='#') s[i] = sub[pos++];
    }

    cout<<(is_sorted(s.begin(),s.end()) ? cost : -1 )<<'\n';

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        func3();
    }
    return 0;
}