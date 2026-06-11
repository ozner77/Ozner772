#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> V;
vector<vector<ll>> adj;
vector<ll> dp;
vector<ll> ans;
void dfs(ll cur,ll p){
    for(auto x:adj[cur]){
        if(x!=p){
            dfs(x,cur);
            if(dp[x]>0){
                dp[cur]+=dp[x];
            }
        }
    }
    dp[cur]+=V[cur];
}
void reroot(ll cur, ll p){
    if(dp[cur]>0){
        dp[p]-=dp[cur];
    }
    if(dp[p]>0){
        dp[cur]+=dp[p];
    }
    ans[cur]=dp[cur];
    for(auto x:adj[cur]){
        if(x!=p)reroot(x,cur);
    }
    if(dp[p]>0){
        dp[cur]-=dp[p];
    }
    if(dp[cur]>0){
        dp[p]+=dp[cur];
    }
}
int main(){
    ll n;
    cin>>n;
    V.resize(n);
    adj.resize(n);
    dp.resize(n);
    ans.resize(n);
    for(int i=0;i<n;i++){
        cin>>V[i];
        if(V[i]==0){
            V[i]--;
        }
    }
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,-1);
    ans[0]=dp[0];
    for(auto x:adj[0]){
        reroot(x,0);
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
}