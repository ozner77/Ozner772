#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD=1e9+7;
ll n,k;
vector<vector<ll>> mult(vector<vector<ll>> A,vector<vector<ll>> B){
    vector<vector<ll>> RES(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                RES[i][j]+=((A[i][k]%MOD)*(B[k][j]%MOD))%MOD;
                RES[i][j]%=MOD;
            }
        }
    }
    return RES;
}
int main(){
    cin>>n>>k;
    vector<vector<ll>> V(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>V[i][j];
        }
    }
    vector<vector<vector<ll>>> XD(61);
    XD[0]=V;
    for(int i=1;i<61;i++){
        XD[i]=mult(XD[i-1],XD[i-1]);
    }
    ll ck=k;
    ll primero=true;
    vector<vector<ll>> ans(n,vector<ll>(n,0));
    ll ind=0;
    for(int i=0;i<n;i++){
        ans[i][i]=1;
    }
    while(ck>0){
        if(ck%2!=0){
            ans=mult(ans,XD[ind]);
        }
        ck/=2;
        ind++;
    }
    ll ansi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ansi=(ansi+ans[i][j])%MOD;
        }
    }
    cout<<ansi%MOD;
}