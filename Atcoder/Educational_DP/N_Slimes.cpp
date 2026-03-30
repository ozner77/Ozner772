#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> V;
vector<vector<ll>> dp;
vector<ll> P;
void solve(ll l,ll r){
    if(l==r){
        dp[l][r]=0;
        return;
    }
    if(dp[l][r]!=1e18){
        return;
    }
    for(int i=l;i<r;i++){
        solve(l,i);
        solve(i+1,r);
        dp[l][r]=min(dp[l][i]+P[r+1]-P[l]+dp[i+1][r],dp[l][r]);
    }
}
int main(){
    ll n;
    cin>>n;
    dp.assign(n,vector<ll>(n,1e18));
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    P.push_back(0);
    for(int i=0;i<n;i++){
        P.push_back(P[i]+V[i]);
    }
    solve(0,n-1);
    cout<<dp[0][n-1];
}