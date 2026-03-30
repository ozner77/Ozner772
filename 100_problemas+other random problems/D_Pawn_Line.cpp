#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> xd(2);
        vector<vector<ll>> dp(n,xd);
        dp[0][0]=0;
        dp[0][1]=0;
        vector<ll> V;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        ll a=V[0];
        ll b=V[0];
        for(int i=1;i<n;i++){
            if(V[i]==a){
                
            }
        }
    }
}