#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    ll MOD=1e9+7;
    vector<vector<ll>> dp(n,vector<ll>(k+1));
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    for(int i=0;i<=V[0];i++){
        dp[0][i]=1;
    }
    for(int i=1;i<n;i++){
        ll valor=0;
        for(int j=0;j<=k;j++){
            valor=(valor+dp[i-1][j])%MOD;
            if(j-V[i]>0){
                valor=(valor-dp[i-1][j-V[i]-1]+MOD)%MOD;
            }
            dp[i][j]=valor;
        }
    }
    cout<<dp[n-1][k]%MOD;
}