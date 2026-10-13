#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll MOD=1e9+7;
    vector<vector<ll>> grid(n,vector<ll>(n,0)),dp(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char a;
            cin>>a;
            if(a=='*'){
                grid[i][j]++;
            }
        }
    }
    if(grid[0][0]==0){
        dp[0][0]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                if(i>0){
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]%=MOD;
                }
                if(j>0){
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=MOD;
                }
            }
        }
    }
    cout<<dp[n-1][n-1];
}