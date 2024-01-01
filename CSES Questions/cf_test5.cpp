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

// #define
// ((a+b)%M ) = ((a%M)+(b%M))%M  (a*b)%M=(a%m * b%m)%M
// (a-b)%M=((a%M)-(b%M))%M  (a/b)%M=((a%M)* (b^-1)%M)%M

//#define priority_queue
//priority_queue<int> maxi;      max heap
//priority_queue<int,vector<int>,greater<int>> mini;     min heap
//priority_queue<pair<int.int>,vector<pair<int,int>>,greater<pair<int,int>>;      forpair of priority queue
//functions
//mini.push() , mini.pop(),mini.top(),mini.size();

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
    map<int,int> m;
    for(int i=0;i<3;i++){
        int x;cin>>x;
        m[x]++;
    }
    for(auto i:m){
        if(i.second==1){
            cout<<i.first<<endl;
            return;
        }
    }
}
void func2(){
    char mat[3][3];
    int x=0,y=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>mat[i][j];
            if(mat[i][j] == '?'){
                x=i,y=j;
            }
        }
    }
    map<char,int> m;
    m['A']=0;m['B']=0;m['C']=0;
    for(int i=0;i<3;i++){
        if(mat[x][i] != '?'){
            m[mat[x][i]]++;
        }
    }
    char ans;
    for(auto it:m){
        if(it.second == 0){
            ans=it.first;
        }
    }
    cout<<ans<<endl;
}

void func3(){
    ll n, sum=0;cin>>n;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        sum += x;
    }
    ll ans = sqrt(sum);
    if(ans*ans == sum ){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
}
void func4(){
    ll n;cin>>n;
    string s;cin>>s;
    vector<pair<char,char>> v;
    for(int i=0;i<n;i++){
        char val;
        if(s[i] == 'a' || s[i] == 'e') val = 'V';
        else val = 'C';
        v.push_back({s[i],val});
    }

    string ans ="";
    int i;
    for( i=n-1;i>=2;){
        string temp="";
        if(v[i].second == 'V' && v[i-1].second == 'C' && v[i-2].second == 'V' && i-2>=0){
            temp += v[i].first + v[i-1].first + v[i-2].first + '.';
            i-=3;
        }
        else if(v[i].second == 'V' && v[i-1].second == 'C'){
            temp += v[i].first + v[i-1].first + '.';
            i-=2;
        }
        else{
            i--;
        }
        ans += temp;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}
void find_subarray(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> prefix_sum(n+1, 0);
    for(int i=0; i<n; i++) {
        prefix_sum[i+1] = prefix_sum[i] + ((i % 2 == 0) ? a[i] : -a[i]);
    }

    map<int, int> first_occurrence;
    first_occurrence[0] = 0;
    for(int i=1; i<=n; i++){
        if(first_occurrence.count(prefix_sum[i])){
            cout << "YES" << endl;
            return;
        }
        if(first_occurrence.count(prefix_sum[i]) == 0){
            first_occurrence[prefix_sum[i]] = i;
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;cin>>t;
    while(t--){
        // func4();
        find_subarray();
    }
    return 0;
}