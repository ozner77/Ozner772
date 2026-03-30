#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> V(n,vector<char>(m));
    vector<vector<ll>> dp(n,vector<ll>(m,0));
    ll MOD=1e9+7;
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>V[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(V[i][j]=='#'){
                continue;
            }
            if(i-1>=0){
                dp[i][j]+=(dp[i-1][j])%MOD;
                dp[i][j]%=MOD;
            }
            if(j-1>=0){
                dp[i][j]+=dp[i][j-1]%MOD;
                dp[i][j]%=MOD;
            }
        }
    }
    cout<<dp[n-1][m-1]%MOD;
}