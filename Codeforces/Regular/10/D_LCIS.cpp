#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> A,B;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        A.push_back(a);
    }
    ll m;
    cin>>m;
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        B.push_back(a);
    }
    vector<ll> dp(m);
    ll recons=0;
    map<ll,ll> rebuild;
    ll ans=0;
    for(int i=0;i<m;i++){
        rebuild[i]=-1;
    }
    for(int i=0;i<n;i++){
        pair<ll,ll> record={0,-1};
        for(int j=0;j<m;j++){
            if(A[i]==B[j]){
                dp[j]=record.first+1;
                rebuild[j]=record.second;
            }else if(A[i]>B[j]){
                if(dp[j]>record.first){
                    record={dp[j],j};
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        if(dp[i]>ans){
            ans=dp[i];
            recons=i;
        }
    }
    vector<ll> respuesta;
    while(recons!=-1){
        respuesta.push_back(B[recons]);
        recons=rebuild[recons];
    }
    reverse(respuesta.begin(),respuesta.end());
    cout<<ans<<"\n";
    if(ans>0){
        for(auto x:respuesta){
            cout<<x<<" ";
        }
    }
}