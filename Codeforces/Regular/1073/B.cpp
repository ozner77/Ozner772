#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        ll con0=0;
        ll con1=0;
        cin>>n;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a==0){
                con0++;
            }else if(a==1){
                con1++;
            }
        }
        if(con0==0){
            cout<<"NO\n";
        }else if(con0==1){
            cout<<"YES\n";
        }else{
            if(con1==0){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
        }
    }
}