#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> V;
    ll ans=0;
    for(int i=0;i<2*n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
        if(i>=2){
            if(V[i]==V[i-2]){
                ans++;
            }
        }
    }
    cout<<ans;
}