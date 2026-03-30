#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    unordered_map<ll,ll> M;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        M[a]++;
    }
    ll k;
    cin>>k;
    ll ans=0;
    for(int i=k;i<=100;i++){
        ans+=M[i];
    }
    cout<<ans;
}