#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll xd;
vector<bool> visited;
vector<vector<ll>> adj;
void dfs(ll cur){
    xd++;
    visited[cur]=true;
    for(auto x:adj[cur]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
int main(){
    ll n,m;
    cin>>n>>m;
    adj.resize(n);
    visited.assign(n,false);
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            xd=0;
            dfs(i);
            xd=xd*(xd-1);
            xd/=2;
            xd-=
            ans+=xd;
        }
    }
    cout<<ans-m;
}