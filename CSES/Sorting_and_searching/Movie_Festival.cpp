#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> V;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        V.push_back({b,a});
    }
    sort(V.begin(),V.end());
    ll act=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(V[i].second>=act){
            act=V[i].first;
            ans++;
        }
    }
    cout<<ans;
}