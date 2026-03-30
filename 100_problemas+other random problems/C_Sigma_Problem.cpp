#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll MOD=1e8;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        ll xd=((n-1)%MOD*(a%MOD))%MOD;
        ans=(ans+xd)%MOD;
    }
    cout<<ans;
}