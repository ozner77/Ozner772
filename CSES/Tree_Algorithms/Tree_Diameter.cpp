#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<ll> dp;
ll ans=0;
void dfs(ll cur,ll p){
    ll maxi1=0;
    ll maxi2=0;
    for(auto x:adj[cur]){
        if(x!=p){
            dfs(x,cur);
            if(dp[x]>maxi1){
                maxi2=maxi1;
                maxi1=dp[x];
            }else if(dp[x]>maxi2){
                maxi2=dp[x];
            }
        }
    }
    dp[cur]=maxi1+1;
    ans=max(ans,maxi1+maxi2);
}
int main(){
    ll n;
    cin>>n;
    adj.resize(n);
    dp.resize(n,1);
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,-1);
    cout<<ans;
}