#include <bits/stdc++.h>
using namespace std;
#define ll long double
int main(){
    int n;
    cin>>n;
    vector<ll> A,B;
    A.push_back(0);
    B.push_back(0);
    for(int i=0;i<n;i++){
        ll xd;
        cin>>xd;
        ll uwu=1-xd;
        A.push_back(xd);
        B.push_back(uwu);
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j>0){
                dp[i][j]+=dp[i-1][j-1]*A[i];
            }
            dp[i][j]+=dp[i-1][j]*B[i];
        }
    }
    int xd=(n+1)/2;
    ll ans=0;
    for(int i=xd;i<=n;i++){
        ans+=dp[n][i];
    }
    cout<<fixed<<setprecision(10)<<ans;
}