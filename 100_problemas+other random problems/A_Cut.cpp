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
    for(int i=n-k;i<n;i++){
        cout<<V[i]<<" ";
    }
    for(int i=0;i<n-k;i++){
        cout<<V[i]<<" ";
    }
}