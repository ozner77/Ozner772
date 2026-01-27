#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll xd(ll a,ll b){
    ll c=a+b;
    string xde=to_string(c);
    reverse(xde.begin(),xde.end());
    ll jaja=stoll(xde);
    return jaja;
}
int main(){
    ll x,y;
    cin>>x>>y;
    vector<ll> V;
    V.push_back(x);
    V.push_back(y);
    for(int i=2;i<10;i++){
        V.push_back(xd(V[i-1],V[i-2]));
    }
    cout<<V[9];
}