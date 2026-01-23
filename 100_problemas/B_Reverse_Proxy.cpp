#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll> V(n+1,0);
    for(int i=0;i<q;i++){
        ll a;
        cin>>a;
        if(a>0){
            V[a]++;
            cout<<a<<" ";
        }else{
            ll mini=1e18;
            ll miniballs=1e18;
            for(ll j=1;j<=n;j++){
                if(miniballs>V[j]){
                    miniballs=V[j];
                    mini=j;
                }else if(miniballs==V[j]){
                    mini=min(mini,j);
                }
            }
            V[mini]++;
            cout<<mini<<" ";
        }
    }
}