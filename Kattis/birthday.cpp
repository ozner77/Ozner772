#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<ll> tin,low;
vector<bool> vis;
ll tim;
bool ok;
void dfs(ll cur,ll prev){
    vis[cur]=true;
    low[cur]=tim;
    tin[cur]=tim;
    tim++;
    for(auto x:adj[cur]){
        if(vis[x] && x!=prev){
            low[cur]=min(low[cur],tin[x]);
        }else if(x!=prev){
            dfs(x,cur);
            low[cur]=min(low[cur],low[x]);
            if(low[x]>tin[cur]){
                ok=true;
            }
        }
    }
}
int main(){
    while(true){
        ll a,b;
        cin>>a>>b;
        if(a==0 && b==0){
            break;
        }
        adj.clear();
        tin.clear();
        low.clear();
        vis.clear();
        tim=0;
        ok=false;
        tin.resize(a);
        adj.resize(a);
        low.resize(a);
        vis.assign(a,false);
        for(int i=0;i<b;i++){
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(0,-1);
        for(int i=0;i<a;i++){
            if(!vis[i]){
                ok=true;
            }
        }
        if(ok){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}