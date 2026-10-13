#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll val=n/i;
            ans+=(val*val);
        }
        cout<<ans<<"\n";
    }
}