#include <bits/stdc++.h>
vector<int> nextGreaterElementII(vector<int>& a) {
    // Write your code here.

    stack<int> s;
    int n = a.size();
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        s.push(a[i]);
    }
    
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top()>a[i]){
            ans.push_back(s.top());
        }
        else{
            while(!s.empty() && s.top() <= a[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
