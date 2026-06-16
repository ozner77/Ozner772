#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        vector<ll> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        ll ans=0;
        ll mx=-1e18,mn=1e18;

        for(int i=0;i<n;i++){
            ans+=abs(a[i]-b[i]);
            mx=max(mx,min(a[i],b[i]));
            mn=min(mn,max(a[i],b[i]));
        }

        ans+=max(0LL,2*(mx-mn));
        cout<<ans<<"\n";
    }
}