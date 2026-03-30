#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> dp(n,1e9);
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    dp[0]=0;
    dp[1]=abs(V[1]-V[0]);
    for(int i=k;i<n;i++){
        for(int j=1;j<=k;j++){
            
        }
    }
    cout<<dp[n-1];
}