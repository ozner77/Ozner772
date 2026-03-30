#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    vector<ll> ans;
    for(int i=0;i<n-1;i++){
        ans.push_back(V[i]*V[i+1]);
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
}