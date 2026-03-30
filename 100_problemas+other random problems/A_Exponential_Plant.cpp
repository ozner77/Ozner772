#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll ans=0;
    ll n;
    cin>>n;
    ll cur=1;
    for(int i=0;i<64;i++){
        ans+=cur;
        if(ans>n){
            cout<<i+1;
            break;
        }
        cur*=2;
    }
}