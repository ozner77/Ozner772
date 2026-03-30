#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> dp(k+1,-1);
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    for(int i=0;i<V[0];i++){
        dp[i]=0;
    }
    sort(V.begin(),V.end());
    for(int i=V[0];i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-V[j]<0){
                continue;
            }
            if(dp[i]==1){
                continue;
            }else if(dp[i-V[j]]==0){
                dp[i]=1;
            }else if(dp[i-V[j]]==1){
                dp[i]=0;
            }
        }
    }
    if(dp[k]==1){
        cout<<"First";
    }else{
        cout<<"Second";
    }
}