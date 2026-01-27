#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> T;
vector<ll> V;
void build(ll i,ll l,ll r){
    if(l==r){
        T[i]=V[l];
        return;
    }
    ll m=(l+r)/2;
    build(2*i+1,l,m);
    build(2*i+2,m+1,r);
    T[i]=T[2*i+1]+T[2*i+2];
}
void upd(ll i,ll l,ll r,ll a,ll b){
    if (a<l || a>r){
        return;
    }
    if(l==r){
        T[i]=b;
        return;
    }
    ll m = (l + r) / 2;
    upd(2*i+1, l, m, a, b);
    upd(2*i+2, m+1, r, a, b); 
    T[i]=T[2*i+1]+T[2*i+2];

}
ll qu(ll i,ll l,ll r,ll tl,ll tr){
    if(l>tr || r<tl){
        return 0;
    }
    if(l<=tl && tr<=r){
        return T[i];
    }
    ll m=(tl+tr)/2;
    return qu(2*i+1,l,r,tl,m)+qu(2*i+2,l,r,m+1,tr);
}
int main(){
    ll n,q;
    cin>>n>>q;
    T.resize(4*n);
    V.clear();
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    build(0,0,n-1);
    for(int i=0;i<q;i++){
        ll a;
        cin>>a;
        if(a==1){
            ll b;
            cin>>b;
            b--;
            ll aux=V[b];
            upd(0,0,n-1,b,V[b+1]);
            upd(0,0,n-1,b+1,V[b]);
            V[b]=V[b+1];
            V[b+1]=aux;
        }else{
            ll b,c;
            cin>>b>>c;
            b--;
            c--;
            ll ans=qu(0,b,c,0,n-1);
            cout<<ans<<"\n";
        }
    }
}