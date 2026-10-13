#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
ll ans;
ll dfs(ll cur,ll depth) {
    ll mx1=depth;
    ll mx2=depth;
    for(ll x1:adj[cur]) {
            ll x=dfs(x1,depth+1);
            if(x>mx1) {
                mx2=mx1;
                mx1=x;
            }else if(x>mx2){
                mx2=x;
            }
    }
    ans+=mx2-depth+1;
    return mx1;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        adj.clear();
        adj.resize(n);
        ans=0;
        for(int i=1;i<n;i++){
            ll a;
            cin>>a;
            adj[a-1].push_back(i);
        }
        dfs(0,0);
        cout<<ans<<"\n";
    }
}