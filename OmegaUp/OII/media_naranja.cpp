#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,pair<ll,ll>>> inter;
vector<ll> A,T;
void build(ll i,ll l,ll r){
    if(l==r){
        T[i]=A[l];
        return;
    }
    ll mid=(l+r)/2;
    build(2*i,l,mid);
    build(2*i+1,mid+1,r);
    T[i]=T[2*i]+T[2*i+1];
}
ll query(ll i,ll l,ll r,ll x,ll y){
    if(l>=x && r<=y) return T[i];
    if(l>y || r<x) return 0;
    ll mid=(l+r)/2;
    return query(2*i,l,mid,x,y)+query(2*i+1,mid+1,r,x,y);
}
ll update(ll i,ll l,ll r,ll pos,ll val){
    if(l>pos || r<pos) return T[i];
    if(l==r){
        T[i]-=val;
        return T[i];
    }
    ll mid=(l+r)/2;
    T[i]=update(2*i,l,mid,pos,val)+update(2*i+1,mid+1,r,pos,val);
    return T[i];
}
map<ll,ll> compress;
set<ll> uni;
vector<ll> mids;
int main(){
    ll n;
    cin>>n;
    A.resize(3*n);
    T.resize(12*n);
    for(ll i=0;i<n;i++){
        ll l,r,m;
        cin>>l>>r;
        m=(l+r);
        l*=2;
        r*=2;
        uni.insert(l);
        uni.insert(r);
        uni.insert(m);
        inter.push_back({r-l,{l,r}});
        mids.push_back(m);
    }
    ll idx=0;
    sort(inter.begin(),inter.end());
    for(auto x:uni){
        compress[x]=idx++;
    }
    for(auto x:mids){
        A[compress[x]]++;
    }
    build(1,0,A.size()-1);
    ll ansi=0;
    for(auto x:inter){
        ll l=compress[x.second.first];
        ll r=compress[x.second.second];
        ansi+=query(1,0,A.size()-1,l,r)-1;
        update(1,0,A.size()-1,compress[(x.second.first+x.second.second)/2],1);
    }
    cout<<ansi<<"\n";
}