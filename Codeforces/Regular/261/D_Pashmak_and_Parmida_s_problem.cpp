#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> V,T;
ll sumi(ll ind){
    ll ans=0;
    while(ind>0){
        ans+=T[ind];
        ind-=(ind&-ind);
    }
    return ans;
}
void upd(ll ind,ll val){
    while(ind<T.size()){
        T[ind]+=val;
        ind+=(ind&-ind);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    V.resize(n+1);
    T.resize(n+1);
    vector<ll> vals;
    for(int i=0;i<n;i++){
        cin>>V[i+1];
        vals.push_back(V[i+1]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for(int i = 1; i <= n; i++){
        V[i] = lower_bound(vals.begin(), vals.end(), V[i]) - vals.begin();
    }
    vector<ll> M(vals.size(), 0);
    vector<ll> XD(vals.size(), 0);
    for(int i=n;i>0;i--){
        M[V[i]]++;
        upd(M[V[i]],1);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        XD[V[i]]++;
        upd(M[V[i]],-1);
        M[V[i]]--;
        ans+=sumi(XD[V[i]]-1);
    }
    cout<<ans;
}