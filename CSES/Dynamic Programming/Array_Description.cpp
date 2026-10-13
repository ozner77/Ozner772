#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> V(n);
    vector<vector<ll>> dp(n,vector<ll>(m+2,0));
    ll mod=1e9+7;
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    if(V[0]>0){
        dp[0][V[0]]=1;
    }else{
        for(int i=1;i<=m;i++){
            dp[0][i]=1;
        }
    }
    for(int i=1;i<n;i++){
        if(V[i]>0){
            dp[i][V[i]]=(dp[i-1][V[i]]+dp[i-1][V[i]-1]+dp[i-1][V[i]+1])%mod;
        }else{
            for(int j=1;j<=m;j++){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1])%mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=mod;
    }
    cout<<ans;
}