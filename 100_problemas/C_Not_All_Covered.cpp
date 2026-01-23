#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> V(n+2,0);
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        V[a]++;
        V[b+1]--;
    }
    vector<ll> Pv;
    Pv.push_back(0);
    for(int i=0;i<n;i++){
        Pv.push_back(Pv[i]+V[i+1]);
    }
    ll ans=1e18;
    for(int i=1;i<=n;i++){
        ans=min(ans,Pv[i]);
    }
    cout<<ans;
}