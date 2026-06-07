#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<vector<ll>> V;
ll ans=0;
ll n,k;
void dfs(ll cur,ll p){
    for(auto x:adj[cur]){
        if(x!=p){
            dfs(x,cur);
            for(int i=1;i<=500;i++){
                V[cur][i]+=V[x][i-1];
            }
        }
    }
    V[cur][0]=1;
}
void reroot(ll cur,ll p){
    for(int i=1;i<=500;i++){
        V[p][i]-=V[cur][i-1];
    }
    for(int i=1;i<=500;i++){
        V[cur][i]+=V[p][i-1];
    }
    ans+=V[cur][k];
    for(auto x:adj[cur]){
        if(x!=p){
            reroot(x,cur);
        }
    }
    for(int i=1;i<=500;i++){
        V[cur][i]-=V[p][i-1];
    }
    for(int i=1;i<=500;i++){ 
        V[p][i]+=V[cur][i-1];
    }
}
int main(){
    cin>>n>>k;
    adj.resize(n);
    V.assign(n,vector<ll>(501,0));
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,-1);
    ans=(V[0][k]);
    for(auto x:adj[0]){
        reroot(x,0);
    }
    cout<<(ans/2);
}