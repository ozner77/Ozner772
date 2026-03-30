#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    unordered_set<ll> S;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        S.insert(a);
    }
    for(auto x:S){
        if(x<=k){
            ans-=x;
        }
    }
    ll uwu=k;
    uwu*=(uwu+1);
    uwu/=2;
    ans+=uwu;
    cout<<ans;
}