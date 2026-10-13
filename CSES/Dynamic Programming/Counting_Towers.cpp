#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<ll> dp(1e6+1,0);
    ll MOD=1e9+7;
    dp[0]=0;
    dp[1]=2;
    dp[2]=8;
    for(int i=3;i<=1e6;i++){
        dp[i]=(6*dp[i-1]-7*dp[i-2]+7*MOD)%MOD;
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
}