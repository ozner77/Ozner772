#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ok;
vector<ll> visited;
vector<vector<ll>> adj;
vector<ll> memo;
ll solve(ll cur){
    if(memo[cur]!=-1){
        return memo[cur];
    }
    if(adj[cur].size()==0){
        return 1;
    }
    ll ans=-1;
    ll xd;
    for(auto x:adj[cur]){
        ll uwu=solve(x);
        if(uwu>ans){
            ans=uwu;
            xd=x;
        }
    }
    if(cur<xd){
        memo[cur]=ans;
        return ans;
    }
    memo[cur]=ans+1;
    return ans+1;
}
void dfs(ll cur){
    visited[cur]=1;
    for(auto x:adj[cur]){
        if(visited[x]==1){
            ok=false;
            return;
        }else if(visited[x]==0){
            dfs(x);
        }
    }
    visited[cur]=2;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ok=true;
        visited.assign(n,0);
        vector<ll> V;
        adj.clear();
        adj.resize(n);
        memo.assign(n,-1);
        for(int i=0;i<n;i++){
            ll k;
            cin>>k;
            if(k==0){
                V.push_back(i);
            }
            for(int j=0;j<k;j++){
                ll a;
                cin>>a;
                a--;
                adj[a].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        if(ok){
            ll ans=-1;
            for(auto x:V){
                ans=max(ans,solve(x));
            }
            cout<<ans<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}