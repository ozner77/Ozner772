#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,o;
    cin>>n>>m>>o;
    vector<pair<ll,ll>> V;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        V.push_back({a,b});
    }
    sort(V.begin(),V.end());
    priority_queue<pair<ll,ll>> pq;
    vector<ll> ganancias;
    vector<pair<ll,ll>> pedidos;
    ll ind=0;
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        pedidos.push_back({b,a});
    }
    sort(pedidos.begin(),pedidos.end());
    for(int i=0;i<n;i++){
        ll newind=ind-1;
        for(int j=ind;j<m;j++){
            if(pedidos[j].first<=V[i].second){
                pq.push({pedidos[j].second,pedidos[j].first});
            }else{
                break;
            }
            newind=j;
        }
        ind=newind+1;
        ll xd=0;
        if(!pq.empty()){
            xd=pq.top().first;
        }
        if(xd>V[i].first){
            pq.pop();
            ganancias.push_back(xd-V[i].first);
        }
    }
    sort(ganancias.rbegin(),ganancias.rend());
    ll ans=0;
    for(int i=0;i<min(o,(ll)ganancias.size());i++){
        ans+=ganancias[i];
    }
    cout<<ans;
}