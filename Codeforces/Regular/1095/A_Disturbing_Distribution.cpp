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
            if(x!=1){
                V.push_back(x);
            }
            if(i==n-1 && x==1){
                V.push_back(x);
            }
        }
        if(V.size()==0){
            cout<<1<<"\n";
        }else{
            ll ans=0;
            for(auto x:V){
                ans+=x;
            }
            cout<<ans<<"\n";
        }
    }
}