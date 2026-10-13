#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> A;
        map<ll,ll> M;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            A.push_back(a);
        }
        for(int i=0;i<m;i++){
            ll a;
            cin>>a;
            M[a-1]++;
        }
        ll pos=0;
        vector<vector<ll>> dp(n+1,vector<ll>(2,-1e18));
        dp[n][0]=0;
        dp[n][1]=-1e18;
        ll leidos=0;
        for(int i=n-1;i>=0;i--){
            if(M[i]>0){
                dp[i][0]=max(dp[i+1][0],dp[i+1][1]);
                dp[i][1]=dp[i][0];
                leidos++;
            }else{
                dp[i][0]=dp[i+1][0];
                dp[i][1]=dp[i+1][1];
            }
            dp[i][0]+=A[i];
            if(leidos>0){
                dp[i][1]-=A[i];
            }
        }
        cout<<max(dp[0][0],dp[0][1])<<"\n";
    }
}