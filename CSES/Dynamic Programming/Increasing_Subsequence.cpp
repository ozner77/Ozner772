#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    vector<ll> V;
    vector<ll> dp;
    dp.push_back(-1);
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        auto ind=lower_bound(dp.begin(),dp.end(),a);
        if(ind==dp.end()){
            dp.push_back(a);
        }else{
            ll indice=ind-dp.begin();
            dp[indice]=a;
        }
    }
    cout<<dp.size()-1;
}