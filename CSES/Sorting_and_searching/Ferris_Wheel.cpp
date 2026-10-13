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
    sort(V.begin(),V.end());
    ll l=0;
    ll r=n-1;
    ll ans=0;
    while(l<r){
        if(V[l]+V[r]<=k){
            l++;
            r--;
        }else{
            r--;
        }
        if(l==r){
            ans++;
        }
        ans++;
    }
    cout<<ans;
}