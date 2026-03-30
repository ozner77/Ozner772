#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD=1e9+7;
int main() {
    string k;
    cin>>k;
    ll d;
    cin>>d;
    vector<vector<vector<ll>>> dp(k.size()+1,vector<vector<ll>>(d,vector<ll>(2,0)));
    dp[0][0][1]=1;
    for(ll i=0;i<k.size();i++){
        for(ll j=0;j<d;j++){
            for(ll t=0;t<2;t++){
                if(dp[i][j][t]==0){
                    continue;
                }
                ll limit;
                if(t==1){
                    limit=k[i]-'0';
                } else {
                    limit=9;
                }
                for(ll ind=0;ind<=limit;ind++){
                    ll nj=(j+ind)%d;
                    ll nt;
                    if(t==1){       
                        if(ind==limit)  
                            nt=1;       
                        else
                            nt=0;       
                    }else{
                        nt=0;         
                    }
                    dp[i+1][nj][nt]=dp[i+1][nj][nt]+dp[i][j][t];
                    dp[i+1][nj][nt]%=MOD;
                }
            }
        }
    }

    ll ans=(dp[k.size()][0][0]+dp[k.size()][0][1]-1+MOD)%MOD;
    cout<<ans;
}