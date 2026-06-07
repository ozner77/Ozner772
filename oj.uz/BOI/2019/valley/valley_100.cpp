#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<ll,ll>,ll> M;
map<pair<ll,ll>,ll> M2;
vector<vector<ll>> adj;
vector<ll> depth;
vector<vector<ll>> a;
vector<vector<ll>> cost;
vector<vector<ll>> dp;
vector<ll> val;
map<ll,ll> tienda;
vector<ll> transi;
ll logi=20;
void dfs(ll u,ll p){
    if(tienda[u]) val[u]=0;
    if(p!=-1) depth[u]=depth[p]+1;
    a[u][0]=p;
    for(ll i=1;i<logi;i++){
        if(a[u][i-1]!=-1)a[u][i]=a[a[u][i-1]][i-1];
    }
    for(auto x:adj[u]){
        if(x!=p){dfs(x,u);
            val[u]=min(val[u],val[x]+M[{u,x}]);
            transi[M2[{u,x}]]=x;
        }
    }
}
void dfs2(ll u,ll p){
    if(p!=-1){
    cost[u][0]=M[{u,p}]+val[p];
    dp[u][0]=cost[u][0];
    }   
    for(ll i=1;i<logi;i++){
        if(a[u][i-1]!=-1){
            cost[u][i]=cost[a[u][i-1]][i-1]+cost[u][i-1]-val[a[u][i-1]];
            dp[u][i]=min(dp[u][i-1],cost[u][i-1]-val[a[u][i-1]]+dp[a[u][i-1]][i-1]);
        }
    }
    for(auto x:adj[u]){
        if(x!=p){
            dfs2(x,u);
        }
    }
}
ll lca(ll x,ll y){
    if(depth[x]<depth[y]) swap(x,y);
    ll diff=depth[x]-depth[y];
    for(ll i=0;i<logi;i++){
        if(diff&(1LL<<i)) x=a[x][i];
    }
    if(x==y) return x;
    for(ll i=logi-1;i>=0;i--){
        if(a[x][i]!=a[y][i]){
            x=a[x][i];
            y=a[y][i];
        }
    }
    return a[x][0];    
}
ll respuesta(ll u, ll k) {
    ll res = val[u];
    ll sumi = 0;
    for (int i = 0; i < logi; i++) {
        if ((k >> i) & 1) {
            res = min(res, sumi+dp[u][i]);
            sumi += (cost[u][i]-val[a[u][i]]);
            u = a[u][i];
        }
    }
    return res;
}
int main(){
    ll n,s,q,e;
    cin>>n>>s>>q>>e;
    adj.resize(n);
    depth.resize(n);
    val.assign(n,1e16);
    transi.resize(n);
    a.resize(n,vector<ll>(logi,-1));
    cost.assign(n, vector<ll>(logi, 2e18));
    dp.assign(n, vector<ll>(logi, 2e18));
    for(ll i=0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        M[{a,b}]=c;
        M[{b,a}]=c;
        M2[{a,b}]=i;
        M2[{b,a}]=i;
    }
    for(ll i=0;i<s;i++){
        ll a;
        cin>>a;
        a--;
        tienda[a]=1;
    }
    dfs(e-1,-1);
    dfs2(e-1,-1);
    for(ll i=0;i<q;i++){
        ll x,b;
        cin>>x>>b;
        x--;b--;
        ll na=transi[x];
        ll lowest=lca(na,b);
        if(lowest==na){
            ll uwunt=respuesta(b,depth[b]-depth[lowest]);
            if(uwunt>1e14){
                cout<<"oo\n";
            }else{
                cout<<uwunt<<"\n";
            }
        }else{
            cout<<"escaped\n";
        }
    }
}