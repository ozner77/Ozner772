#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll ans=0;
        ans+=(d/2);
        if(a%2!=0 && b%2!=0 && c%2!=0){
            ans++;
        }
        ans+=(a/2);
        ans+=(b/2);
        ans+=(c/2);
        cout<<ans<<"\n";
    }
}