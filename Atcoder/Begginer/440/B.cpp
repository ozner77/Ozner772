#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<pair<ll,ll>> V;
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back({a,i+1});
    }
    sort(V.begin(),V.end());
    for(int i=0;i<3;i++){
        cout<<V[i].second<<" ";
    }
}