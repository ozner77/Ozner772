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
        sort(V.begin(),V.end());
        ll mid=V[0]+V[n-1];
        mid/=2;
        ll ans=max(abs(V[0]-mid),abs(V[n-1]-mid));
        cout<<ans<<endl;
    }
}