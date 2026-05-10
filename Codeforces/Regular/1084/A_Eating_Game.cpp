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
        ll maxi=-1e18;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            maxi=max(maxi,a);
            M[a]++;
        }
        cout<<M[maxi]<<"\n";
    }
}