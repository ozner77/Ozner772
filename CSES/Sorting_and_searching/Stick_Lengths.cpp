#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> V(n);
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    sort(V.begin(),V.end());
    ll xd=V[n/2];
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(V[i]-xd);
    }
    cout<<ans;
}