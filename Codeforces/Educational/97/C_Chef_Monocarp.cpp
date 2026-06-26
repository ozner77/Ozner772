#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        vector<ll> V;
        ll n;
        cin>>n;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        sort(V.begin(),V.end());
        vector<vector<ll>> dp(2*n,vector<ll>(n+1,1e18));
        for(int i=0;i<2*n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<2*n;j++){
                dp[j][i]=min(dp[j-1][i],dp[j-1][i-1]+abs(V[i-1]-j));
            }
        }
        ll ans=1e18;
        for(int i=0;i<2*n;i++){
            ans=min(ans,dp[i][n]);
        }
        cout<<ans<<"\n";
    }
}