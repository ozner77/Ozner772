#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
        }
        if(n==1){
            cout<<1;
        }else{
            for(int i=0;i<n;i++){
                cout<<2<<" ";
            }
        }
        cout<<"\n";
    }
}