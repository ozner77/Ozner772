#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    ll l=0;
    map<ll,ll> M;
    ll ans=0;
    ll dis=0;
    for(ll r=0;r<n;r++){
        M[V[r]]++;
        if(M[V[r]]==1){
            dis++;
        }
        if(dis>k){
            while(dis>k){
                M[V[l]]--;
                if(M[V[l]]==0){
                    dis--;
                }
                l++;
            }
        }
        ans+=(r-l)+1;
    }
    cout<<ans;
}