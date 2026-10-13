#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        ll n=a.size();
        ll m=b.size();
        vector<ll> A,B;
        vector<ll> S1,S2;
        for(int i=0;i<n;i++){
            A.push_back(a[i]-'0');
        }
        for(int i=0;i<m;i++){
            B.push_back(b[i]-'0');
        }
        ll cur=0;
        for(int i=0;i<n;i++){
            S1.push_back((cur+A[i])%10);
            cur=S1[i];
        }
        cur=0;
        for(int i=0;i<m;i++){
            S2.push_back((cur+B[i])%10);
            cur=S2[i];
        }
        vector<ll> dp(m,0);
        for(int i=0;i<n;i++){
            ll maxi=0;
            for(int j=0;j<m;j++){
                if(S1[i]==S2[j]){
                    if(maxi+1>dp[j]){
                        dp[j]=maxi+1;
                    }else{
                        maxi=max(maxi,dp[j]);
                    }
                }else{
                    maxi=max(maxi,dp[j]);
                }
            }
        }
        if(S2.back()!=S1.back()){
            cout<<-1<<"\n";
        }else{
            ll ans=0;
            for(auto x:dp){
                ans=max(ans,x);
            }
            cout<<ans<<"\n";
        }
    }
}