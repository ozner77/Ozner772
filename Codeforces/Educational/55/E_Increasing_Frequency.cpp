#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> V;
    map<ll,ll> M;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        M[a]++;
        V.push_back(a);
    }
    vector<ll> dp(1000000,0);
    vector<ll> dpmax(1000000,0);
    ll cur=0;
    for(int i=0;i<n;i++){
        dp[V[i]]++;
        if(V[i]==k){
            cur++;
        }
        if(dp[V[i]]-cur<=0 && V[i]!=k){
            dp[V[i]]=cur+1;
        }
        dpmax[V[i]]=max(dpmax[V[i]],dp[V[i]]-cur);
    }
    ll maxi=0;
    for(int i=0;i<1e6;i++){
        maxi=max(maxi,dpmax[i]);
    }
    cout<<M[k]+maxi;
}