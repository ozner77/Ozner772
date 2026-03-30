#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> A;
    ll tmp=n;
    while(tmp>0){
        A.push_back(tmp%10);
        tmp/=10;
    }
    reverse(A.begin(),A.end());
    ll L=A.size();
    ll res=0;
    for(int suma=1;suma<=9*L;suma++){
        vector<vector<vector<vector<ll>>>> dp(L+1,vector<vector<vector<ll>>>(suma+1,vector<vector<ll>>(suma,vector<ll>(2))));
        dp[0][0][0][0]=1;
        for(int d=0;d<L;d++){
            for(int i=0;i<=suma;i++){
                for(int j=0;j<suma;j++){
                    for(int f=0;f<=1;f++){
                        if(dp[d][i][j][f]==0){
                            continue;
                        }
                        for(int t=0;t<=9;t++){
                            if(i+t>suma) continue;
                            ll nf=f;
                            if(f==0 && t<A[d]){
                                nf=1;
                            }
                            if(f==0 && t>A[d]){
                                continue;
                            }
                            ll nj=(10*j+t)%suma;
                            dp[d+1][i+t][nj][nf]+=dp[d][i][j][f];
                        }
                    }
                }
            }
        }
        res+=dp[L][suma][0][0]+dp[L][suma][0][1];
    }
    cout<<res<<"\n";
    return 0;
}