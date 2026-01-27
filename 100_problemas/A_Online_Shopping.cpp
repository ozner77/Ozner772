#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,s,k;
    cin>>n>>s>>k;
    vector<pair<ll,ll>> V;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        V.push_back({a,b});
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a=V[i].first;
        ll b=V[i].second;
        ans+=a*b;
    }
    if(ans<s){
        ans+=k;
    }
    cout<<ans<<"\n";
}