#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,h,l;
        cin>>n>>h>>l;
        if(h>l){
            swap(h,l);
        }
        ll H=0;
        ll L=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a<=h){
                H++;
            }else if(a<=l){
                L++;
            }
        }
        ll ans=min(H,L);
        H=H-ans;
        ans+=(H/2);
        cout<<ans<<"\n";
    }
}