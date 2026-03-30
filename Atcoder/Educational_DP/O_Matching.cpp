#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin>>n;
    vector<vector<ll>> V(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>V[i][j];
        }
    }
    ll xd=1;
    for(int i=0;i<n;i++){
        xd*=2;
    }
    vector<ll> dp(xd,0);
    dp[0]=1;
    for(int i=0;i<xd;i++){
        ll cop=i;
        ll hom=0;
        while(cop>0){
            if(cop%2!=0){
                hom++;
            }
            cop/=2;
        }
        for(int j=0;j<n;j++){
            if(!(i&(1<<j)) && V[hom][j]==1){
                dp[i|(1<<j)]+=dp[i];
                dp[i|(1<<j)]%=MOD;
            }
        }
    }
    cout<<dp[xd-1]%MOD;
}