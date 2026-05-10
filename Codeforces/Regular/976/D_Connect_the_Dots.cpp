#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> P,R;
void init(ll n){
    P.resize(n);
    R.resize(n);
    for(ll i=0;i<n;i++){
        P[i]=i;
        R[i]=0;
    }
}
ll encontrar(ll x){
    if(P[x]==x){
        return x;
    }
    return P[x]=encontrar(P[x]);
}
void unir(ll a,ll b){
    a=encontrar(a);
    b=encontrar(b);
    if(a!=b){
        if(R[a]<R[b]){
            swap(a,b);
        }
        P[b]=a;
        if(R[a]==R[b]){
            R[a]++;
        }
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> dp(n,vector<ll>(11,0));
        for(int i=0;i<m;i++){
            ll a,d,k;
            cin>>a>>d>>k;
            dp[a-1][d]++;
            ll xd=(a-1)+d*k;
            if(xd<n){
                dp[xd][d]--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<=10;j++){
                if(i-j>=0){
                    dp[i][j]+=dp[i-j][j];
                }
            }
        }
        init(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<=10;j++){
                if(i-j>=0){
                    if(dp[i-j][j]>0){
                        unir(i,i-j);
                    }
                }
            }
        }
        set<ll> S;
        for(int i=0;i<n;i++){
            S.insert(encontrar(i));
        }
        cout<<S.size()<<"\n";
    }
}