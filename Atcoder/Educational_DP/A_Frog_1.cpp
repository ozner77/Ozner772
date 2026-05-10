#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<ll> dp,V;
    ll n;
    cin>>n;
    dp.resize(n);
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    dp[1]=abs(V[0]-V[1]);
    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1]+abs(V[i]-V[i-1]),dp[i-2]+abs(V[i]-V[i-2]));
    }
    cout<<dp[n-1];
}