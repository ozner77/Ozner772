#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        unordered_set<ll> S;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            S.insert(a);
        }
        vector<ll> dp(n+1,1e18);
        for(int i=1;i<=n;i++){
            if(S.count(i)>0){
                dp[i]=1;
            }else{
                ll xd=sqrt(i);
                xd++;
                for(ll j=1;j<=xd;j++){
                    if(i%j==0){
                        ll uwu=i/j;
                        if(S.count(uwu)>0 && S.count(j)>0){
                            dp[i]=min(dp[i],dp[uwu]+dp[j]);
                            S.insert(i);
                        }
                    }
                }
            }
        }
        for(int i=1;i<dp.size();i++){
            if(dp[i]==1e18){
                cout<<-1<<" ";
            }else{
                cout<<dp[i]<<" ";
            }
        }
        cout<<"\n";
    }
}