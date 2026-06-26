#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> V;
ll compress(ll x){
    auto it=lower_bound(V.begin(),V.end(),x);
    ll ans=it-V.begin();
    return ans;
}
int main(){
    ll n;
    cin>>n;
    map<ll,ll> M;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        b++;
        V.push_back(a);
        V.push_back(b);
        M[a]++;
        M[b]--;
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    vector<ll> vals(V.size());
    ll act=0;
    for(int i=0;i<V.size();i++){
        act+=M[V[i]];
        vals[i]=act;
    }
    vector<ll> ans(n+1);
    for(int i=1;i<vals.size();i++){
        ll dist=V[i]-V[i-1];
        ans[vals[i-1]]+=dist;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}