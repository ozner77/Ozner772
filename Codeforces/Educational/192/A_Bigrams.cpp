#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        bool ok=false;
        ll xd=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a>=3){
                ok=true;
                xd++;
            }else if(a>=2){
                xd++;
            }
        }
        if(xd>=2 || ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}