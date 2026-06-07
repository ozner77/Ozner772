#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            V.push_back(x);
        }
        map<ll,ll> M;
        for(auto x:V){
            M[x]++;
        }
        ll ans=0;
        for(auto x:M){
            if(x.second>=x.first){
                ans+=(x.second-x.first);
            }else{
                ans+=x.second;
            }
        }
        cout<<ans<<"\n";
    }
}