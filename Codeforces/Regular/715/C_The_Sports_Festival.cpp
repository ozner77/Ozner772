#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    map<ll,ll> M;
    vector<pair<ll,ll>> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        M[a]++;
    }
    for(auto x:M){
        V.push_back({x.first,x.second});
    }
    sort(V.begin(),V.end());
    vector<vector<ll>> dp(V.size(),vector<ll>(V.size(),1e18));
    for(int i=0;i<V.size();i++){
        dp[i][i]=0;
    }
    for(int i=1;i<V.size();i++){
        for(int j=0;j<V.size()-i;j++){
            dp[j][j+i]=min(dp[j+1][j+i]+(abs(V[j+i].first-V[j].first)*V[j].second),dp[j][j+i-1]+(abs(V[j+i].first-V[j].first)*V[j+i].second));
        }
    }
    cout<<dp[0][V.size()-1];
}