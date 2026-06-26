#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<bool> visited;
void dfs(ll cur){
    visited[cur]=true;
    for(auto x:adj[cur]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
int main(){
    ll n;
    cin>>n;
    adj.resize(n);
    visited.assign(n,false);
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        a--;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans;
}