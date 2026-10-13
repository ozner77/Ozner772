#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    ll MOD=1e9+7;
    ll limit=(1<<n);
    vector<vector<ll>> dp(n,vector<ll>(limit,0));
    vector<vector<ll>> adj(n,vector<ll>(n,0));
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a][b]++;
    }
    dp[0][1]=1;
    for(int mask=0;mask<limit;mask++){
        for(int i=0;i<n;i++){
            if(dp[i][mask]==0)continue;
            if((mask & (1<<i))==0)continue;
            for(int j=0;j<n;j++){
                ll new_mask=mask | (1<<j);
                if(adj[i][j]>0 && (mask & (1<<j))==0){
                    dp[j][new_mask]=((dp[i][mask]*adj[i][j])+dp[j][new_mask])%MOD;
                }
            }
        }
    }
    cout<<dp[n-1][limit-1];
}