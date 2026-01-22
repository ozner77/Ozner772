#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        ll ans=0;
        if(n%2!=0){
            n--;
            ans+=a;
        }
        if(2*a<=b){
            ans+=n*a;
        }else{
            ans+=(n*b)/2;
        }
        cout<<ans<<"\n";
    }
}