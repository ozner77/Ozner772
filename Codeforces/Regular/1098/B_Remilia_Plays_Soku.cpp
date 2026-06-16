#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,x,x2,k;
        cin>>n>>x>>x2>>k;
        if(n<=3){
            cout<<1<<"\n";
        }else{
            ll ansi1;
            ll ansi2;
            if(x2>x){
                ansi1=x2-x;
                x+=n;
                ansi2=x-x2;
            }else{
                ansi1=x-x2;
                x2+=n;
                ansi2=x2-x;
            }
            ll ans=min(ansi1,ansi2);
            ans+=k;
            cout<<ans<<"\n";
        }
    }
    
}