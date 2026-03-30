#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    ll n;
    cin>>n;
    vector<ll> V,pV,pvR;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    pV.push_back(V[0]);
    for(int i=0;i<n;i++){
        pV.push_back(gcd(pV[i],V[i]));
    }
    reverse(V.begin(),V.end());
    pvR.push_back(V[0]);
    for(int i=0;i<n;i++){
        pvR.push_back(gcd(pvR[i],V[i]));
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll uwu,uwunt;
        if(i-1>0){
            uwu=pV[i-1];
        }else{
            uwu=pvR[n-i];
        }
        if(i+1<=n){
            uwunt=pvR[n-i];
        }else{
            uwunt=pV[i-1];
        }
        ans=max(ans,gcd(uwu,uwunt));
    }
    if(n==2){
        ans=max(V[0],V[1]);
    }
    cout<<ans;
}