#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll q,k;
    cin>>q>>k;
    vector<ll> dp(k+1,0);
    ll MOD=998244353;
    dp[0]=1;
    for(int i=0;i<q;i++){
        char a;
        ll b;
        cin>>a>>b;
        if(a=='+'){
            for(int j=k;j>=b;j--){
                dp[j]=(dp[j-b]+dp[j])%MOD;
            }
        }else{
            for(int j=b;j<=k;j++){
                dp[j]=(dp[j]-dp[j-b]+MOD)%MOD;
            }
        }
        cout<<dp[k]<<"\n";
    }
}