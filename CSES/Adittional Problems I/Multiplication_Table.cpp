#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll l=0;
    ll r=1e16;
    ll k=(n*n+1)/2;
    while(l<r){
        ll mid=(l+r)/2;
        ll xd=0;
        for(int i=1;i<=n;i++){
            xd+=min(n,mid/i);
        }
        if(xd>=k){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l;
}