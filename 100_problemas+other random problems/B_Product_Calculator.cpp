#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    ll cur=1;
    ll limit=1;
    for(int i=0;i<k;i++){
        limit*=10;
    }
    limit--;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        if(limit/a>=cur){
            cur*=a;
        }else{
            cur=1;
        }
    }
    cout<<cur;
}