#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<ll> V(3);
    cin>>V[0]>>V[1]>>V[2];
    sort(V.begin(),V.end());
    ll ans=min((V[0]+V[2]+V[1])/3,V[0]+V[1]);
    cout<<ans;
}