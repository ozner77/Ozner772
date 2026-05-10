#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll MOD=1e9+7;
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    vector<vector<char>> grid(n);
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(auto x:s){
            grid[i].push_back(x);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!='*'){
                if(i-1>=0){
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]%=MOD;
                }
                if(j-1>=0){
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=MOD;
                }
            }
        }
    }
    if(grid[0][0]=='*'){
        dp[n-1][n-1]=0;
    }
    cout<<dp[n-1][n-1]%MOD<<"\n";
}