#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<vector<ll>> a;
ll logi=20;
void dfs(ll cur,ll p){
    a[cur][0]=p;
    for(int i=1;i<logi;i++){
        if(a[cur][i-1]!=-1){
            a[cur][i]=a[a[cur][i-1]][i-1];
        }
    }
    for(auto x:adj[cur]){
        if(x!=p){
            dfs(x,cur);
        }
    }
}
ll get(ll cur,ll k){
    for(int i=0;i<logi;i++){
        if(k & (1<<i)){
            cur=a[cur][i];
            if(cur==-1){
                return cur;
            }
        }
    }
    return cur;
}
int main(){
    ll n,q;
    cin>>n>>q;
    adj.resize(n);
    a.assign(n,vector<ll>(20,-1));
    for(int i=0;i<n-1;i++){
        ll a;
        cin>>a;
        a--;
        adj[a].push_back(i+1);
        adj[i+1].push_back(a);
    }
    dfs(0,-1);
    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        ll ans=get(a,b);
        ans++;
        if(ans!=-1){
        }
        cout<<ans<<"\n";
    }
}