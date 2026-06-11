#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> Parent;
vector<ll> Rank;
void init(ll n){
    Parent.resize(n);
    Rank.resize(n);
    for(int i=0;i<n;i++){
        Parent[i]=i;
        Rank[i]=0;
    }
}
ll Find(ll u){
    if(Parent[u]==u){
        return u;
    }
    return Parent[u]=Find(Parent[u]);
}
void Union(ll u,ll v){
    u=Find(u);
    v=Find(v);
    if(u!=v){
        if(Rank[u]>Rank[v]){
            Parent[v]=u;
        }else if(Rank[v]>Rank[u]){
            Parent[u]=v;
        }else{
            Parent[v]=u;
            Rank[u]++;
        }
    }
}
int main(){
    ll caca,k;
    cin>>caca>>k;
    vector<ll> V;
    ll xd;
    cin>>xd;
    ll suma=max(xd,0ll);
    for(int i=1;i<caca;i++){
        ll a;
        cin>>a;
        if(a<0 && xd<0){
            xd+=a;
        }else if(a>0 && xd>0){
            xd+=a;
        }else{
            V.push_back(xd);
            xd=a;
        }
        if(a>0){
            suma+=a;
        }
    }
    V.push_back(xd);
    ll n=V.size();
    ll con=0;
    vector<pair<ll,ll>> P;
    for(int i=0;i<n;i++){
        if(V[i]<0){
            P.push_back({V[i],i});
        }else{
            con++;
        }
    }
    if(k>=con){
        cout<<suma;
        return 0;
    }
    
}