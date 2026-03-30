#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> visited;
vector<vector<ll>> G;
void dfs(ll cur){
    visited[cur]=true;
    for(auto x:G[cur]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
int main(){
   ll n,m;
    cin>>n>>m;
    unordered_map<ll,ll> A;
    G.resize(n+1);
    if(n==m){
        for(int i=0;i<n;i++){
            ll a,b;
            cin>>a>>b;
            A[a]++;
            A[b]++;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(auto x:A){
            if(x.second!=2){
                cout<<"No";
                return 0;
            }
        }
        visited.resize(n+1,false);
        visited[0]=true;
        dfs(1);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                cout<<"No";
                return 0;
            }
        }
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}