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
        V.push_back({a,b});
    }
    sort(V.begin(),V.end());
    ll ans=0;
    ll time=0;
    for(int i=0;i<n;i++){
        time+=V[i].first;
        ans+=V[i].second-time;
    }
    cout<<ans;
}