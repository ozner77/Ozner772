#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        vector<ll> V;
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            if(x<l){
                ans+=(l-x);
            }else if(x>r){
                ans+=(x-r);
            }else{
                V.push_back(x);
            }
        }
        sort(V.begin(),V.end());
        for(int i=0;i<V.size()/2;i++){
            ans+=V[V.size()-1-i]-V[i];
        }
        if(n%2==1){
            ll xd=V[V.size()/2];
            ans+=min(xd-l,r-xd);
        }
        cout<<ans<<"\n";
    }
}