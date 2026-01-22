#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll limit;
ll cur;
ll curneg;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V,L;
        vector<vector<pair<ll,ll>>> adj;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        for(int i=0;i<n;i++){
            ll b;
            cin>>b;
            b--;
            L.push_back(b);
        }
        adj.resize(n);
        for(int i=1;i<n;i++){
            adj[i].push_back({i-1,0});
        }
        for(int i=0;i<n;i++){
            if(L[i]>i){
                adj[i].push_back({L[i],V[i]});
            }
        }
        vector<ll> prefix;
        prefix.push_back(0);
        for(int i=0;i<n;i++){
            prefix.push_back(V[i]+prefix[i]);
        }
        vector<ll> dist(n,1000000000000000);
        dist[0]=0;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0,0}); 
        while(!pq.empty()){
            ll no=pq.top().second;
            ll w=pq.top().first;
            pq.pop();
            if(w>dist[no]){
                continue;
            }
            for(auto x:adj[no]){
                if(dist[x.first]>dist[no]+x.second){
                    dist[x.first]=dist[no]+x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        ll ans=V[0];
        for(ll i=1;i<n;i++){
            ans=max(ans,prefix[i+1]-dist[i]);
        }
        cout<<ans<<"\n";
    }
}