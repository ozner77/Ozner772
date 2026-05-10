#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        ll ans=-1e18;
        sort(V.begin(),V.end());
        for(int i=1;i<n;i+=2){
            ans=max(ans,abs(V[i]-V[i-1]));
        }
        cout<<ans<<"\n";
    }
}