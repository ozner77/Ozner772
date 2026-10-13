#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    vector<vector<ll>> dp(k+1,vector<ll>(k+1,0));
    dp[0][0]=1;
    for(auto x:V){
        for(int i=k;i>=0;i--){
            for(int j=k-i;j>=0;j--){
                if(i>=x){
                    dp[i][j]|=dp[i-x][j];
                }
                if(j>=x){
                    dp[i][j]|=dp[i][j-x];
                }
            }
        }
    }
    vector<ll> ans;
    for(int i=0;i<=k;i++){
        if(dp[i][k-i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans){
        cout<<x<<" ";
    }
}