#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    sort(V.begin(),V.end());
    for(int i=0;i<q;i++){
        ll base,nth;
        cin>>base>>nth;
        ll l =base, r =base + nth + n;
        ll ans=-1;
        while(l<=r){
            ll m=(l+r)/2;
            ll bad_m = upper_bound(V.begin(), V.end(), m)-V.begin();
            ll bad_b = lower_bound(V.begin(), V.end(), base)-V.begin();
            ll good = (m-base+1)-(bad_m-bad_b);
            if(good>=nth){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        cout<<l<<"\n";
    }
}