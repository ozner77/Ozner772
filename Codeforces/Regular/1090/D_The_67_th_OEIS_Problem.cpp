#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V;
        ll con=1;
        for(int i=1;i<=n;i++){
            ll ans=con*(con+2);
            con+=2;
            V.push_back(ans);
        }
        for(int i=0;i<n;i++){
            cout<<V[i]<<" ";
        }
        cout<<"\n"; 
    }
}