#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    ll l=0;
    ll r=1e18+1;
    while(l<r){
        ll mid=(l+r)/2;
        ll xd=0;
        for(int i=0;i<n;i++){
            xd+=mid/V[i];
            if(xd>=k){
                break;
            }
        }
        if(xd>=k){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<r;
}