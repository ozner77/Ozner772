#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<ll,ll> M;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            M[a]++;
        }
        ll ans=0;
        ans+=min(M[1],M[2]);
        ll xd=abs(M[1]-M[2]);
        ans+=xd/3;
        ans+=M[0];
        cout<<ans<<"\n";
    }
}