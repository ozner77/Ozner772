#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll maxi=0;
        ll suma=0;
        vector<ll> V;
        for(int i=0;i<7;i++){
            ll a;
            cin>>a;
            suma-=a;
            V.push_back(a);
        }
        ll ans=-1e18;
        for(auto x:V){
            suma+=2*x;
            ans=max(ans,suma);
            suma-=2*x;
        }
        cout<<ans<<"\n";
    }
}