#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<ll> time_in;
vector<ll> time_out;
vector<ll> transi;
map<pair<ll,ll>,ll> M;
ll tim=0;
void dfs(ll u,ll p){
    time_in[u]=++tim;
    for(auto x:adj[u]){
        if(x!=p){
            dfs(x,u);
            transi[M[{u,x}]]=x;
        }
    }
    time_out[u]=++tim;
}
int main(){
    ll n,s,q,e;
    cin>>n>>s>>q>>e;
    adj.resize(n);
    time_in.resize(n,-1);
    time_out.resize(n,-1);
    transi.resize(n-1);
    for(ll i=0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        M[{a,b}]=i;
        M[{b,a}]=i;
    }
    for(ll i=0;i<s;i++){
        ll a;
        cin>>a;
    }
    dfs(e-1,-1);
    for(ll i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        a=transi[a];
        if(time_in[a]<=time_in[b] && time_out[a]>=time_out[b]){
            cout<<0<<"\n";
        }else{
            cout<<"escaped\n";
        }
    }
}