#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        ll ans=0;
        ll mini=1e18;
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            mini=min(mini,x);
            ans+=mini;
        }
        cout << ans << "\n";
    }
}