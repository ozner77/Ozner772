#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        bool ok=true;
        ll extra=0;
        for(int i=1;i<=n;i++){
            ll a;
            cin>>a;
            if(a+extra>=i){
                extra+=(a-i);
            }else{
                ok=false;
            }
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}