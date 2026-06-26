#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> vals;
ll compress(ll x){
    auto it=lower_bound(vals.begin(),vals.end(),x);
    ll ans=it-vals.begin();
    return ans;
}
int main(){
    ll n,q;
    cin>>n>>q;
    map<ll,ll> M;
    for(int i=0;i<n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        vals.push_back(a);
        vals.push_back(b);
        M[a]+=c;
        M[b]-=c;
    }
    vector<pair<ll,ll>> queries;
    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        vals.push_back(a);
        vals.push_back(b);
        queries.push_back({a,b});
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<ll> prefix(vals.size(),0);
    ll act=0;
    for(int i=0; i<vals.size()-1; i++){
        act += M[vals[i]];
        ll dist = vals[i+1] - vals[i];
        prefix[i+1] = prefix[i] + (act * dist);
    }
    for(auto x:queries){
        ll l=x.first;
        ll r=x.second;
        l=compress(l);
        r=compress(r);
        ll val1=0;
        ll val2=0;
        if(l>=0){
            val1=prefix[l];
        }
        val2=prefix[r];
        cout<<val2-val1<<"\n";
    }
}