#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        vector<vector<ll>> dp(n,vector<ll>(2,n));
        dp[0][0]=V[0];
        if(n>1){
            dp[1][0]=V[0]+V[1];
        }
        for(int i=1;i<n;i++){
            dp[i][0]=min(dp[i][0],dp[i-1][1]+V[i]);
            dp[i][1]=min(dp[i][1],dp[i-1][0]);
            if(i>1){
                dp[i][0]=min(dp[i][0],dp[i-2][1]+V[i]+V[i-1]);
                dp[i][1]=min(dp[i][1],dp[i-2][0]);
            }
        }
        cout<<min(dp[n-1][0],dp[n-1][1])<<"\n";
    }
}