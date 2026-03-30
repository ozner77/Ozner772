#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string x,y;
    ll a,b;
    cin>>x>>y;
    a=x.size();
    b=y.size();

    vector<vector<ll>> dp(a+1,vector<ll>(b+1,-1e9));
    for(int i=0;i<=a;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=b;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans="";
    ll i=a;
    ll j=b;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            ans+=x[i-1];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}