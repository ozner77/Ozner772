#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<ll> S;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            S.insert(a);
        }
        vector<ll> V;
        for(auto x:S){
            V.push_back(x);
        }
        ll ans=1;
        ll con=1;
        for(int i=1;i<V.size();i++){
            if(V[i]==V[i-1]+1){
                con++;
            }else{
                ans=max(ans,con);
                con=1;
            }
        }
        ans=max(ans,con);
        cout<<ans<<"\n";
    }
}