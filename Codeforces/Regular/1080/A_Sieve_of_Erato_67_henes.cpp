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
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a==67){
                ok=true;
            }
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}