#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll suma=0;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
        suma+=a;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        suma-=V[i];
        ans+=V[i]*(suma);
    }
    cout<<ans;
}