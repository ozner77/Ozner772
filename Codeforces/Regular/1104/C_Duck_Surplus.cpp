#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        vector<ll> V(n);
        for(int i=0;i<n;i++){
            cin>>V[i];
        }
        ll ans=V[0];
        for(int i=1;i<n;i++){
            if(ans<=V[i]){
                ans=V[i];
            }else{
                ans+=V[i];
            }
        }
        cout<<ans<<"\n";
    }
}