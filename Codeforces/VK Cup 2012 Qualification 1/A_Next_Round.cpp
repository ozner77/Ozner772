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
    sort(V.rbegin(),V.rend());
    ll ans=0;
    for(auto x:V){
        if(x>=V[k-1] && x>0){
            ans++;
        }
    }
    cout<<ans;
}