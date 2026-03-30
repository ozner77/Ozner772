#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;
vector<bool> visited;
vector<vector<ll>> adj;
ll MOD=1e9+7;
void solve(ll cur){
    visited[cur]=true;
    dp[cur][0]=1;
    dp[cur][1]=1;
    for(auto x:adj[cur]){
        if(!visited[x]){
            solve(x);
            dp[cur][0]*=(dp[x][0]%MOD+dp[x][1]%MOD)%MOD;
            dp[cur][1]*=dp[x][0]%MOD;
            dp[cur][0]%=MOD;
            dp[cur][1]%=MOD;
        }
    }
    
}
int main(){
    ll n;
    cin>>n;
    visited.assign(n,false);
    adj.resize(n);
    dp.assign(n,vector<ll>(2));
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(0);
    ll ans=dp[0][0]+dp[0][1];
    cout<<ans%MOD;
}