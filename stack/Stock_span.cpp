#include <bits/stdc++.h>

vector<int> findStockSpans(vector<int>& p) {
    // Write your code here.
    vector<int> v;
    int n = p.size();
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(-1);
        }
        else if(!s.empty() && s.top().first >= p[i]){
            v.push_back(s.top().second);
        }
        else{
            while(!s.empty() && s.top().first<p[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push({p[i], i});
    }
    // no need to reverse 
    for(int i=0;i<n;i++){
        v[i] = i-v[i];
    }
    return v;
}
