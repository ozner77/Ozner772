#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        unordered_set<ll> Xl,Xr,Yl,Yr,XlYl,XrYr,XrYl,XlYr;
        ll n;
        cin>>n;

        vector<pair<ll,ll>> X,Y;
        for(int i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            X.push_back({x,i});
            Y.push_back({y,i});
        }
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        for(int i=0;i<n/2;i++){
            Xl.insert(X[i].second);
        }
        for(int i=n/2;i<n;i++){
            Xr.insert(X[i].second);
        }
        for(int i=0;i<n/2;i++){
            Yl.insert(Y[i].second);
        }
        for(int i=n/2;i<n;i++){
            Yr.insert(Y[i].second);
        }
        for(auto x:Xl){
            if(Yl.count(x)){
                XlYl.insert(x);
            }
            if(Yr.count(x)){
                XlYr.insert(x);
            }
        }
        for(auto x:Xr){
            if(Yl.count(x)){
                XrYl.insert(x);
            }
            if(Yr.count(x)){
                XrYr.insert(x);
            }
        }
        vector<ll> ans1A,ans1B,ans2A,ans2B;
        for(auto x:XlYl){
            ans1A.push_back(x);
        }
        for(auto x:XrYr){
            ans1B.push_back(x);
        }
        for(auto x:XlYr){
            ans2A.push_back(x);
        }
        for(auto x:XrYl){
            ans2B.push_back(x);
        }
        for(int i=0;i<ans1A.size();i++){
            cout<<ans1A[i]+1<<" "<<ans1B[i]+1<<"\n";
        }
        for(int i=0;i<ans2A.size();i++){
            cout<<ans2A[i]+1<<" "<<ans2B[i]+1<<"\n";
        }
    }
}