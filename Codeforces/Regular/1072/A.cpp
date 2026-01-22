#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==2){
            cout<<2<<"\n";
        }else if(n==3){
            cout<<3<<"\n";
        }else if(n%2==0){
            cout<<0<<"\n";
        }else{
            cout<<1<<"\n";
        }
    }
}