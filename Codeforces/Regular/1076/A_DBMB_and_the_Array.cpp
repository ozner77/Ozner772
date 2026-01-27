#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,s,x;
        cin>>n>>s>>x;
        ll suma=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            suma+=a;
        }
        if(suma>s){
            cout<<"NO\n";
        }else{
            s=s-suma;
            if(s%x==0){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}