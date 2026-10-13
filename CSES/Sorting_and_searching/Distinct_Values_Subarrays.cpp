#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll con=0;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    ll l=0;
    map<ll,ll> M;
    ll ans=0;
    for(ll r=0;r<n;r++){
        M[V[r]]++;
        if(M[V[r]]==2){
            for(ll i=l;i<=r;i++){
                M[V[i]]--;
                if(V[i]==V[r]){
                    ans+=(r-i);
                    l=i+1;
                    break;
                }
            }
        }else{
            ans+=(r-l)+1;
        }
    }
    cout<<ans;
}