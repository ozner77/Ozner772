#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k,m;
        cin>>n>>k>>m;
        ll xd=m/k;
        ll ans;
        if(xd%2==0){
            ll uwu=m%k;
            ans=n-uwu;
            if(ans<0){
                ans=0;
            }
        }else{
            ll uwu=m%k;
            if(k>n){
                k=n;
            }
            ans=k-uwu;
            if(ans<0){
                ans=0;
            }
        }
        cout<<ans<<"\n";
    }
}