#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll l=0;
    ll r=n*m;
    while(l<r){
        ll mid=(l+r)/2;
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=min(mid/i,m);
        }
        if(ans>=k){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l;
}